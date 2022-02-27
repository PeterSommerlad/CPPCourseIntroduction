#include "word.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
using word::Word;
void thisIsATest() {
	Word w { "hallo" };
	ASSERT_EQUAL("Hallo", w);
}
void emptyWordNotAllowed() {
	ASSERT_THROWS(Word{""}, std::logic_error);
}
void nonAlphaCharactersNotAllowed(){
	ASSERT_THROWS(Word{"a12b"}, std::logic_error);
}
void wordsLessThan(){
	Word const w { "alpha" };
	Word const v { "Beta" };
	ASSERT(w < v);
	ASSERT("Zero">w);
}
void wordOutputOperator(){
	std::ostringstream out;
	Word const w { "hallo" };
	out << w;
	ASSERT_EQUAL("hallo",out.str());
}

void wordInputOperatorOK(){
	std::istringstream in{"Hello Peter"};
	Word w{"original"};
	in >> w;
	ASSERT_EQUAL("Hello",w);
	in >> w;
	ASSERT_EQUAL("Peter",w);
	w = Word{"original"};
	in >> w;
	ASSERT_EQUAL("original",w);
	ASSERT(in.fail());
}
void wordInputOperatorFails(){
	std::istringstream in{};
	Word w{"original"};
	in >> w;
	ASSERT_EQUAL("original",w);
	ASSERT(in.fail());
}
void wordInputOperatorParsesSentences(){
	std::istringstream in{"Hello,world!"};
	Word w{"original"};
	in >> w;
	ASSERT_EQUAL("Hello",w);
	in >> w;
	ASSERT_EQUAL("world",w);
	in >> w;
	ASSERT(in.fail());
}


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	s.push_back(CUTE(emptyWordNotAllowed));
	s.push_back(CUTE(nonAlphaCharactersNotAllowed));
	s.push_back(CUTE(wordsLessThan));
	s.push_back(CUTE(wordOutputOperator));
	s.push_back(CUTE(wordInputOperatorOK));
	s.push_back(CUTE(wordInputOperatorFails));
	s.push_back(CUTE(wordInputOperatorParsesSentences));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
