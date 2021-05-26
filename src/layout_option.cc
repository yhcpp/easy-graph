#include "layout_option.h"
#include <map>

EG_NS_BEGIN

namespace {
	struct Format {
		const char* format;
		const char* postfix;
	};

	std::map<LayoutFormat, Format> formats = {
			{LayoutFormat::ASCII  , {"ascii" , "txt"}},
			{LayoutFormat::BOXART , {"boxart", "txt"}},
			{LayoutFormat::SVG    , {"svg"   , "svg"}},
			{LayoutFormat::DOT    , {"dot"   , "dot"}},
			{LayoutFormat::HTML   , {"html"  , "html"}}
	};

	std::string getLayoutOutputArg(const LayoutOption& options, const std::string& graphName) {
		if (options.output == LayoutOutput::CONSOLE) return "";
		return std::string(" --output ") + options.outputPath + graphName + "." + formats[options.format].postfix;
	}

	std::string getLayoutFomartArg(const LayoutOption& options) {
		return std::string(" --as=") + formats[options.format].format;
	}
}

const LayoutOption& LayoutOption::getDefault() {
	static LayoutOption option;
	return option;
}

std::string LayoutOption::getLayoutCmdArgs(const std::string& graphName) const {
	return getLayoutFomartArg(*this) + getLayoutOutputArg(*this, graphName);
}


EG_NS_END
