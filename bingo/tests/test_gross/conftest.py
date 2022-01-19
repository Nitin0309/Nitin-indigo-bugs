import pytest

from ..dbc.PostgresSQL import Postgres
from ..helpers import get_bingo_meta, get_query_entities
from ..logger import logger

FUNCTION = 'gross'


@pytest.fixture(scope='class')
def entities(indigo):
    entities = get_query_entities(indigo, FUNCTION)
    yield entities
    del entities


@pytest.fixture(scope='class')
def init_db():
    logger.info(f"===== Start of testing {FUNCTION} =====")
    meta = get_bingo_meta(FUNCTION, 'molecules')
    db = Postgres()
    pg_tables = db.create_data_tables(meta['tables'])
    db.import_data(import_meta=meta['import'])
    db.create_indices(meta['indices'])

    yield

    logger.info("Dropping DB...")

    for table in pg_tables:
        logger.info(f'Dropping Postgres table {table}')
        table.drop(db.engine)

    logger.info(f"===== Finish of testing {FUNCTION} =====")
