#include <map>
#include <string>

#include "simp/SimpSolver.h"

namespace Incre{

using namespace std;

class IncreSolver{
public:

	IncreSolver();		//constructor
	~IncreSolver();		//deconstructor

	//PIPOs
	static map<int, int> PIs;
	static map<int, int> POs;

	void open(char* path);		//Open files, including Oracle or Camouflage


protected:
	static const char* Orac_file_path;		//input Oracle file path
	static const char* Came_file_path;		//input Camouflage file path
};

class PIPOfinder : public IncreSolver {
public:
	PIPOfinder();
	~PIPOfinder();

	
	static SimpSolver solver;		//Common used solver for addon and miter, will store the intermediate literal value

	inline void solve(const char* path);	// used to solve both miter and addons

};

class SoluFinder : public IncreSolver {
public:
	SoluFinder();
	~SoluFinder();

protected:
	SimpSolver solver;
};

class MiterSolver : public PIPOfinder {
public:
	MiterSolver();
	~MiterSolver();

private:
	static const char* Miter_file_path;			// Export the miter CNF formatted file into the file below

	inline void buildmiter();		// build CNF formatted miter and export to Miter_file_path
	inline void solve();		// inport Miter_file_path and use solver (decleared in PIPOfinder) solve it

};

class AddonSolver: public PIPOfinder {
public:
	AddonSolver();		// constructor: for copy and init
	~AddonSolver();

	map<int, int> Solution;		// store solution for this iteration

protected:
	static const char* Addon_file_path;		// export Addon circuit to this path
	inline void grabnodes(char* previous_solution_file);
	inline void addconstrains();
};



}