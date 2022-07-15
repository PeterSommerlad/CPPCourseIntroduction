#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "PrintOccurrencesSuite.h"
#include "TopSuite.h"
#include "WordHistogramSuite.h"
#include "HistogramEntrySuite.h"

bool runAllTests(int argc, char const *argv[]) {
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	auto histogramSuite = make_suite_WordHistogramSuite();
	bool success = runner(histogramSuite, "Histogram Tests");
	cute::suite TopSuite = make_suite_TopSuite();
	success &= runner(TopSuite, "Top Tests");

	cute::suite PrintOccurrencesSuite = make_suite_PrintOccurrencesSuite();
	success &= runner(PrintOccurrencesSuite, "PrintOccurrencesSuite");

	cute::suite HistogramEntrySuite = make_suite_HistogramEntrySuite();
	success &= runner(HistogramEntrySuite, "HistogramEntrySuite");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
