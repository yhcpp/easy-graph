#include <cctest/cctest.h>
#include "easy_graph/builder/graph_dsl.h"
#include "easy_graph/layout/graph_layout.h"
#include "easy_graph/layout/engines/graph_easy/graph_easy_executor.h"

USING_EG_NS

namespace {
	struct Integer {
		Integer(int id = 0) : id(id) {
		}

		int getId() const {
			return id;
		}

	private:
		int id;
	};

	struct Label {
		Label(const char* label) : label(label) {
		}

		std::string getId() const {
			return label;
		}

	private:
		std::string label;
	};

	struct Float {
		Float(float value) : value(value) {
		}

		float getValue() const {
			return value;
		}

	private:
		float value;
	};

	#define F_BOX(...) BOXING(Float, getValue, __VA_ARGS__)
	#define BOX(TYPE, ...) BOXING(TYPE, getId, __VA_ARGS__)
}

FIXTURE(GraphBuildTest) {
	GraphEasyExecutor executor;

	BEFORE {
		GraphLayout::getInstance().config(executor);
	}

	TEST("should layout graph success") {
		GRAPH(g1) {
			Node a{BOX(Integer, 2)};
			Node b{BOX(Label, "double")};
			Node c{F_BOX(5.0)};

			CHAIN(NODE(a) -> NODE(b) -> NODE(c));
		});

		ASSERT_TRUE(__EG_OK(g1.layout()));
	}
};
