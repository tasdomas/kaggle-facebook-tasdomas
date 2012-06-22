#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main(int ac, char* av[])
{
	try {

		po::options_description desc("Allowed options");
		desc.add_options()
			("help", "produce help message")
			("train,i", po::value<string>(), "set training set file")
			("test,t", po::value<string>(), "set test file")
			("result,o", po::value<string>(), "set result file")
			;

		po::variables_map vm;
		po::store(po::parse_command_line(ac, av, desc), vm);
		po::notify(vm);

		if (vm.count("help")) {
			cout << desc << "\n";
			return 1;
		}

		if (vm.count("train") && vm.count("test") && vm.count("result")) {
			cout << " Computing results.. " << endl;
		} else {
			cout << "Parameters set incorrectly" << endl;
			cout << desc;
		}
	}
	catch(exception& e) {
		cerr << "error: " << e.what() << "\n";
		return 1;
	}
	catch(...) {
		cerr << "Exception of unknown type!\n";
	}

	return 0;
}
