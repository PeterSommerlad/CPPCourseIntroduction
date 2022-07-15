#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>

void printnice(std::ostream & out, unsigned const i) {
	out.width(7);
	out << i;
	out.width(2);
	out << ' ';
}
void printnice(std::ostream &out, double const x) {
	out << ' ' << std::setw(8) << std::fixed << std::setprecision(2)
        << x;
}
void printnice(std::ostream & out, std::string product) {
	if (product.size() > 8) product.resize(8);
	out << std::setw(8) << product << ' ';
}

void printheader(std::ostream &out, unsigned const limit) {
	printnice(out, "product");
	for (unsigned j = 1; j <= limit; ++j) {
		printnice(out, j);
	}
	out << '\n';
}

struct ProductInfo {
	double      price;
	std::string product;
};

void printProduct(std::ostream &out, unsigned const limit, ProductInfo const product) {
	printnice(out, product.product);
	for (unsigned i = 1; i <= limit; ++i) {
		printnice(out, product.price * i);
	}
	out << ' ' << product.product << '\n';

}

std::vector<ProductInfo> const prices{
	{4.65,"Beer"},
	{9.15,"Moass"},
	{3.85,"Schnapps"},
	{2.95,"Soda"}
};

int main() {
	unsigned const limit {10u};
	printheader(std::cout, limit);
	for (auto const product : prices){
		printProduct(std::cout, limit, product );
	}
}
