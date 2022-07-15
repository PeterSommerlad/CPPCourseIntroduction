#ifndef STATISTICS_H_
#define STATISTICS_H_

#include "Word.h"

#include <map>
#include <set>
#include <tuple>

namespace statistics {
using ::text::Word;

struct HistogramEntry {
	Word word;
	int occurrences;

	bool operator<(HistogramEntry const & other) const {
		if (occurrences > other.occurrences) {
			return true;
		} else if (occurrences == other.occurrences) {
			return word < other.word;
		}
		return false;
	}

	bool operator>(HistogramEntry const & other) const {
		return (other < *this);
	}

	bool operator<=(HistogramEntry const & other) const {
		return !(other < *this);
	}

	bool operator>=(HistogramEntry const & other) const {
		return !(*this < other);
	}

	bool operator==(HistogramEntry const & other) const {
		return std::tie(occurrences, word) == std::tie(other.occurrences, other.word);
	}

	bool operator!=(HistogramEntry const & other) const {
		return !(*this == other);
	}
};

std::ostream& operator <<(std::ostream &out, HistogramEntry const &entry);

std::set<statistics::HistogramEntry> top(std::map<text::Word, int> const &occurrences, int n);

std::map<text::Word, int> histogram(std::istream &in);

void printOccurrences(std::istream &in, std::ostream &out, int n);

}


#endif /* STATISTICS_H_ */
