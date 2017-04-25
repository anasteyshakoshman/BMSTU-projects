#pragma once

#include<map>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<exception>

class Obj {
	std::string Str;
	std::map<std::string, std::string> Values;
public:

	Obj() {}

	Obj(std::string &name, std::map<std::string, std::string> &rhs) {
		Str = name;
		Values = rhs;
	}

	void AddInMap(std::string &fir, std::string&sec){
		Values.insert(std::pair<std::string, std::string>(fir, sec));
	}

	void AddName(std::string &name){
		Str = name;
	}

	std::string find(std::string name) const{
		std::map<std::string, std::string>::const_iterator it = Values.find(name);
		if (it == Values.end()) throw;
		return it->second;
	}

	std::string& find(std::string name){
		std::map<std::string, std::string>::iterator it = Values.find(name);
		if (it == Values.end()) throw;
		return it->second;
	}
	std::vector<std::string> GetNames(){
		std::vector<std::string> vec;
		for (auto &i : Values)
		{
			vec.push_back(i.first);
		}
		return vec;
	}

	std::string GetName(){
		return Str;
	}
};


class Analysis
	:public Obj{
	std::ifstream Ptr; 
	std::vector<Obj> Objects;
	std::vector<std::string> HotNames;
public:
	Analysis(){}

	Analysis(const std::string &rhs)
	{
		Ptr.open(rhs);
		if (!Ptr) {
		}
		std::string st;
		Ptr >> st;
		if (st != "#Scheme") throw;
		while (1) {
			Ptr >> st;
			if (st[0]=='#') break;
			if (st[0] == '\"') {
				int n = st.find('\"', 1);
				if (!n) throw;
				st.erase(st.begin());
				st = st.substr(0, n - 1);
				HotNames.push_back(st);
			}
			else throw;
		}
		if (HotNames.size() == 0) throw;
		while (!Ptr.eof()){
			
			Objects.push_back(AddObject(st));
		}
	}

	Obj AddObject(std::string &st) {
		if (st[0] != '#') throw;
		st.erase(st.begin());
		Obj tmp;
		tmp.AddName(st);
		size_t t = 0;
		while (!Ptr.eof()) {
			Ptr >> st;
			if (st[0]=='#') break;
			if (st[0] == '\"') {
				int n = st.find('\"', 1);
				if (!n) throw;
				st.erase(st.begin());
				st = st.substr(0, n - 1);
			}else throw;
			tmp.AddInMap(HotNames[t], st);
			t++;
		}
		return tmp;
	}

	Obj FindObject(const std::string &rsh) {
		for (auto & val : Objects){
			if (val.GetName() == rsh) return val;
		}
		throw;
	}

	std::vector<std::string> GetAllNameObjects(){
		std::vector<std::string> vec;
		for (auto & i : Objects)
		{
			vec.push_back(i.GetName());
		}
		return vec;
	}
};

