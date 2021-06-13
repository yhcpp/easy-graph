#ifndef HB8913B92_089C_46A1_B44F_BD0F91FCA34D
#define HB8913B92_089C_46A1_B44F_BD0F91FCA34D

#include "easy_graph/infra/scope_guard.h"
#include "easy_graph/infra/symbol.h"
#include "easy_graph/builder/edge_types/default_edge_type.h"

EG_NS_BEGIN

#define REG_DEFAULT_EDGE_TYPE(TYPE)  const static ScopeGuard UNIQUE_NAME(default_edge_type_) {		\
                                		[](){::EG_NS::DefaultEdgeType::getInstance().reg(TYPE);}, 	\
										[](){::EG_NS::DefaultEdgeType::getInstance().reset();}		\
 	 	 	 	 	 	 	 	 	 }

EG_NS_END

#endif
