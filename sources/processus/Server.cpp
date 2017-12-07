/*
 * server.cpp
 *
 *  Created on: 19 Nov 2017
 *      Author: maxch
 */

#include "Server.h"
#include <iomanip>

Server::Server(int nTicks, string tick_unit): nTicks_(nTicks), tick_unit_(tick_unit), temp_data_() {}

Server::~Server() {}

void Server::update(int tic) {
/*
	//Write in GNU
	gnu_ << setprecision(3) << setw(15) << tic;
	for(unsigned int i=0; i< temp_data_.size(); i++) {
		gnu_ << setprecision(3) << setw(15) << temp_data_[i]; //voir exo balle rebondissante pour alignement
	}
	gnu_ << endl;

	if(tic == nTicks_) {
		//Fermeture des fichiers:
<<<<<<< HEAD
<<<<<<< HEAD
		string journal = "[i] ---- Simulation completed ----";
		Server::log_journal(journal);
		cout << journal << endl;
=======
		cout << "[i] ---- Simulation completed ----" << endl;
>>>>>>> e76a824edcc34f60e078cd3444d51c138fb03ebc
=======
		cout << "[i] ---- Simulation completed ----" << endl;
>>>>>>> e76a824edcc34f60e078cd3444d51c138fb03ebc
		Server::close_files();
	}*/
}


//Create and open files
void Server::create_files() {
	journal_.open("journal.txt");
	gnu_.open("gnu.txt");
}

//JOURNAL
void Server::log_journal(string text) {
	journal_ << text << endl;
}

//GNU
void Server::gnu_header(int zone_count) {
	gnu_ << "# time[" << tick_unit_ << "]";
	for(int i = 0; i < zone_count; i++) {
		gnu_ << "    val_phen" << i+1 << "    state_curr"
			 << i+1 << "   val_control" << i+1;
	}
	gnu_ << endl;
}

//Close all files
void Server::close_files() {
	journal_.close();
	gnu_.close();
}