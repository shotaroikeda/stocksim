#include <iostream>
#include <string>
#include <boost/program_options.hpp>
// #include <boost/program_options/option.hpp>
// #include <boost/program_options/options_description.hpp>

namespace po = boost::program_options;

int main(int argc, char** argv) {
	po::options_description desc("Allowed options");
	desc.add_options()
        ("help", "produce help message")
		("ram", po::value<std::string>(), "download more")
        ;
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);

	std::cout << "Hello World!\n";
	std::cout << "Can we find a ram in the args: " << vm.count("ram") << std::endl;

	if (vm.count("ram")) {
		std::cout << "Ram has " << vm["ram"] << std::endl;
	} else {
		std::cout << "Ram doesn't have anything\n";
	}


	return 0;
}
