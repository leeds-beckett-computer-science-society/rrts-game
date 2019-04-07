/*
Copyright (C) 2019 Leeds Beckett Computer Science Society

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/
#include <Logger.h>
#include <sstream>

void rrts::User::Logger::error(const std::string& error, const std::string& caller, int line, bool fexit)
{
	std::stringstream out;
#ifdef EMSCRIPTEN
	out << " [ERROR] " << error << "- " << caller << "(" << std::to_string(line) << ")";
#else
#ifdef linux
	out << "\033[0;31m[ERROR] \033[0m" << error << "- " << caller << "(" << std::to_string(line) << ")";
#endif
#endif

	log.push_back(out.str());

	if (fexit)
		fatal = true;
}

void rrts::User::Logger::flush()
{
	if (!log.empty())
	{
		for (const auto& error : log)
		{
			std::cout << error << "\n";
		}
	}

	if (fatal)
		std::exit(-1);

	log.clear();
}

void rrts::User::Logger::info(const std::string &info)
{
	std::stringstream out;

#ifdef EMSCRIPTEN
	out << " [INFO] "<< info;
#else
#ifdef linux
	out << "\033[0;32m [INFO] " << "\033[0m" << info;
#endif
#endif

	log.push_back(out.str());
}
