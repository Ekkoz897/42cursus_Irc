#include <iomanip>
#include <cstring>
#include <string>
#include <string.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>    	// memset
#include <cstdlib>     	// exit()
#include <sys/socket.h>
#include <netinet/in.h> // sockaddr_in
#include <unistd.h> 	//close()

int	is_port_valid(std::string port_nbr)
{
	if (port_nbr.empty())
	{
        std::cerr << "Error: no port was provided.\n";
        exit(1);
    }
	int	port;
	try
	{
        port = std::stoi(port_nbr);
	}
	catch (const std::invalid_argument& e)
	{
        std::cerr << "Invalid port number: " << port_nbr << "\n";
        exit(1);
    }
	if (port <= 1024 || port > 65535)
	{
        std::cerr << "Port number must be between 1024 and 65535.\n";
        exit(1);
    }
}
//need to compare our project against Weechat/irssi (terminal-based)
// or HexChat (GUI)
int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Usage: " << av[0] << " <port number> <password>" << std::endl;
		return (1);
	}
	std::cout << "---- SERVER ----" << std::endl;
	if(!is_port_valid(av[1]) || !*av[2])
	{
		std::cout << "invalid Port number / Password!" << std::endl;
		return (1);
	}
	// Começar a inicializar o server
	return (0);
}