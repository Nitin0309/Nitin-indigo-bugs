import pytest

# from ..dbc.BingoElastic import BingoElastic
from ..dbc.BingoNoSQL import BingoNoSQL
from ..dbc.PostgresSQL import Postgres
from ..helpers import get_bingo_meta, get_query_entities
from ..logger import logger

FUNCTION = 'substructure'


@pytest.fixture(scope='class')
def entities(indigo):
    entities = get_query_entities(indigo, FUNCTION)
    logger.critical(entities.keys())
    yield entities
    del entities


@pytest.fixture(scope='class')
def init_db(indigo):
    logger.info(f"===== Start of testing {FUNCTION} =====")
    meta = get_bingo_meta(FUNCTION, 'molecules')
    db = Postgres()
    pg_tables = db.create_data_tables(meta['tables'])
    db.import_data(import_meta=meta['import'])
    db.create_indices(meta['indices'])

    db_bingo = BingoNoSQL(indigo)
    db_bingo.import_data(meta['import_no_sql'], 'molecule')

    # db_bingo_elastic = BingoElastic(indigo)
    # db_bingo_elastic.import_data(meta['import_no_sql'], 'molecule')

    yield

    logger.info("Dropping DB...")
    for table in pg_tables:
        logger.info(f'Dropping Postgres table {table}')
        table.drop(db.engine)

    db_bingo.delete_base()

    # db_bingo_elastic.drop()

    logger.info(f"===== Finish of testing {FUNCTION} =====")