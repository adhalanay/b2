//This file is part of Bertini 2.
//
//python/bertini_python.cpp is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//python/bertini_python.cpp is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with python/bertini_python.cpp.  If not, see <http://www.gnu.org/licenses/>.
//
// Copyright(C) 2016 by Bertini2 Development Team
//
// See <http://www.gnu.org/licenses/> for a copy of the license, 
// as well as COPYING.  Bertini2 is provided with permitted 
// additional terms in the b2/licenses/ directory.

// individual authors of this file include:
//
//  James Collins
//  West Texas A&M University
//  Spring 2016
//
//
//  python/bertini_python.cpp:  the main source file for the python interface for bertini.


#include "bertini_python.hpp"


namespace bertini
{
	namespace python
	{
		


		BOOST_PYTHON_MODULE(pybertini) // this name must match the name of the generated .so file.
		{
			object package = scope();
		    package.attr("__path__") = "pybertini";

			ExportContainers();
			
			ExportMpfr();
			
			ExportMinieigen();
		
			SetupFunctionTree();

			{
				scope current_scope;
				std::string new_submodule_name(extract<const char*>(current_scope.attr("__name__")));
				new_submodule_name.append(".function_tree");
				object new_submodule(borrowed(PyImport_AddModule(new_submodule_name.c_str())));
				current_scope.attr("function_tree") = new_submodule;

				scope new_submodule_scope = new_submodule;

				ExportNode();
				ExportSymbols();
				ExportOperators();
				ExportRoots();
			}

			ExportSystem();
			
			ExportParsers();

			ExportTrackers();

			ExportEndgames();
		}
	
	}
}


