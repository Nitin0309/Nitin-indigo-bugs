/****************************************************************************
 * Copyright (C) from 2009 to Present EPAM Systems.
 *
 * This file is part of Indigo toolkit.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ***************************************************************************/

#ifndef __mango_oracle__
#define __mango_oracle__

#include "core/mango_context.h"

#include "oracle/bingo_fingerprints.h"
#include "oracle/mango_shadow_table.h"

namespace indigo
{
    class OracleEnv;

    class BingoOracleContext;

    class MangoOracleContext : public MangoContext
    {
    public:
        explicit MangoOracleContext(BingoContext& context);
        ~MangoOracleContext() override;

        BingoOracleContext& context();

        MangoShadowTable shadow_table;
        BingoFingerprints fingerprints;

        static MangoOracleContext& get(OracleEnv& env, int id, bool lock);
    };


} // namespace indigo

extern const char* bad_molecule_warning;
extern const char* bad_molecule_warning_rowid;
#define TRY_READ_TARGET_MOL                                                                                                                                    \
    try                                                                                                                                                        \
    {

#define CATCH_READ_TARGET_MOL(action)                                                                                                                          \
    }                                                                                                                                                          \
    catch (Scanner::Error & e)                                                                                                                                 \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (MolfileLoader::Error & e)                                                                                                                           \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (Element::Error & e)                                                                                                                                 \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (Graph::Error & e)                                                                                                                                   \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (MoleculeStereocenters::Error & e)                                                                                                                   \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (MoleculeCisTrans::Error & e)                                                                                                                        \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (SmilesLoader::Error & e)                                                                                                                            \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (IcmLoader::Error & e)                                                                                                                               \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (Molecule::Error & e)                                                                                                                                \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (DearomatizationException & e)                                                                                                                       \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (MoleculeAutoLoader::Error & e)                                                                                                                      \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (MoleculePiSystemsMatcher::Error & e)                                                                                                                \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (SkewSymmetricNetwork::Error & e)                                                                                                                    \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (EmbeddingEnumerator::TimeoutException & e)                                                                                                          \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning, e.message());                                                                                                    \
        action;                                                                                                                                                \
    }

#define CATCH_READ_TARGET_MOL_ROWID(rowid, action)                                                                                                             \
    }                                                                                                                                                          \
    catch (Scanner::Error & e)                                                                                                                                 \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (MolfileLoader::Error & e)                                                                                                                           \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (Element::Error & e)                                                                                                                                 \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (Graph::Error & e)                                                                                                                                   \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (MoleculeStereocenters::Error & e)                                                                                                                   \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (MoleculeCisTrans::Error & e)                                                                                                                        \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (SmilesLoader::Error & e)                                                                                                                            \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (IcmLoader::Error & e)                                                                                                                               \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (Molecule::Error & e)                                                                                                                                \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (DearomatizationException & e)                                                                                                                       \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (MoleculeAutoLoader::Error & e)                                                                                                                      \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (MoleculePiSystemsMatcher::Error & e)                                                                                                                \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (SkewSymmetricNetwork::Error & e)                                                                                                                    \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }                                                                                                                                                          \
    catch (EmbeddingEnumerator::TimeoutException & e)                                                                                                          \
    {                                                                                                                                                          \
        env.dbgPrintfTS(bad_molecule_warning_rowid, rowid, e.message());                                                                                       \
        action;                                                                                                                                                \
    }

#endif
