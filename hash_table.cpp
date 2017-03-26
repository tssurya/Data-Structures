#include<bits/stdc++.h>

using namespace std;

const int TABLE_SIZE = 128;

class HashEntry
{
private:
	string key;
	string value;
public:
	HashEntry(string key, string value)
	{
		this->key = key;
		this->key = value;
	}

	string get_key()
	{
		return key;
	}

	string get_value()
	{
		return value;
	}
};

class HashMap
{
private:
	HashEntry **table;
public:
	HashMap()
	{
		table = new HashEntry*[TABLE_SIZE];
		for(int i =0; i<TABLE_SIZE; i++)
		{
			table[i] = NULL;
		}
	}

	//I get the value of the corresponding key;
	string get (string key)
	{
		int hash = key%TABLE_SIZE;

		//until the key is found or it is the end of the table
		while(table[hash]!= NULL and table[hash]->get_key()!=key)
		{
			//linear probing
			hash = (hash+1)%TABLE_SIZE;
		}
		//if the key is not found
		if(table[hash] == NULL)
		{
			return -1;
		}
		//key is found so return the value associated with the key.
		else
		{
			return table[hash]->get_value();
		}
	}

	void put (string key, string valur)
	{
		int hash = key%TABLE_SIZE;

		//until the key is found or it is the end of the table
		while(table[hash]!= NULL and table[hash]->get_key()!=key)
		{
			hash = (hash+1)%TABLE_SIZE;
		}
		//if the key is already existing in the table delete it.
		if(table[hash] != NULL)
		{
			delete table[hash];
		}
		//insert the new key value pair there.
		table[hash] = new HashEntry(key, value);
		
	}

};