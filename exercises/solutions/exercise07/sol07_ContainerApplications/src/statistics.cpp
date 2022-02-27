#include "statistics.h"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <map>
#include <set>
#include <stdexcept>
#include <ostream>
#include <istream>

namespace statistics {

void printOccurrences(std::istream &in, std::ostream &out, int n) {
	auto const occurrences = histogram(in);
	auto const topOccurrences = top(occurrences, n);
	std::copy(std::cbegin(topOccurrences), std::cend(topOccurrences), std::ostream_iterator<HistogramEntry> { out, "\n" });
}

std::map<word::Word, int> histogram(std::istream &in) {
	std::map<word::Word, int> result { };
	std::for_each(std::istream_iterator<word::Word> { in }, std::istream_iterator<word::Word> { }, [&result](auto const &word) {
		result[word]++;
	}
	);
	return result;
}

std::set<statistics::HistogramEntry> top(std::map<word::Word, int> const &occurrences, int n) {
	if (n < 0) {
		throw std::invalid_argument { "n must not be negative" };
	}
	std::set<statistics::HistogramEntry> result { };
	std::transform(std::cbegin(occurrences), std::cend(occurrences), std::inserter(result, std::begin(result)), [](auto const &entry) {
		return HistogramEntry { entry.first, entry.second };
	}
	);
	auto const elementsInResult = std::min(static_cast<std::size_t>(n), result.size());
	auto const start = std::next(std::begin(result), elementsInResult);
	result.erase(start, std::end(result));
	return result;
}

std::ostream& operator <<(std::ostream &out, HistogramEntry const &entry) {
	return out << entry.word << ": " << entry.occurrences;
}

}
