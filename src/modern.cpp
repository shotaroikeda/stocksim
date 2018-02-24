#include <iostream>
#include <string>
#include <numeric>
#include <boost/program_options.hpp>
// #include <boost/program_options/option.hpp>
// #include <boost/program_options/options_description.hpp>

namespace po = boost::program_options;


int main(int argc, char* argv[]) {
	po::options_description desc("Allowed options");
	desc.add_options()
        ("help,h", "Adds shit numbers")
		("ram,r", po::value< std::vector<int> >()->multitoken(), "download more");

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);

	if (vm.count("help")) {
		std::cout << desc << std::endl;
		return 0;
	}

	if (vm.count("ram")) {
		std::vector< int > ram_vect = vm["ram"].as< std::vector < int > >();
		auto mult = [](const int &a, const int &b) { return a*b; };
		int prod = std::accumulate(ram_vect.begin(), ram_vect.end(), 1, mult);

		std::cout << "Ram : " << std::to_string(prod) << std::endl;
	} else {
		std::cout << "You little shit I wanted numbers\n";
	}


	return 0;
}
