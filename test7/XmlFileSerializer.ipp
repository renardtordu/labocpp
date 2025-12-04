#include "XmlFileSerializer.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "XmlFileSerializerException.h"

template <typename T>
const char XmlFileSerializer<T>::READ = 'r';
template <typename T>
const char XmlFileSerializer<T>::WRITE = 'w';

template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string& fn, const char m, const string& cn)
{
	filename = fn;
	mode = m;
	collectionName = cn;
	if (isWritable())
	{
		file.open(getFilename(), ios::out);
		if(!file.is_open())
		{
			throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "fichier pas trouver");
		}
		file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
		file<< "<"<<getCollectionName()<<">"<<endl;
	}
	else
	{
		file.open(getFilename(), ios::in);
		if(!file.is_open())
		{
			throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "fichier pas trouver");
		}
		string l;
		getline(file, l);
		getline(file, l);
		l = l.substr(1, l.length() - 2);
		collectionName = l;
	}
}
template <typename T>
bool XmlFileSerializer<T>::isReadable()
{
	if(mode==READ)
		return true;
	return false;
}
template <typename T>
bool XmlFileSerializer<T>::isWritable()
{
	if(mode==WRITE)
		return true;
	return false;
}
template <typename T>
string XmlFileSerializer<T>::getFilename()const
{
	return filename;
}
template <typename T>
string XmlFileSerializer<T>::getCollectionName()const
{
	return collectionName;
}
template <typename T>
void XmlFileSerializer<T>::write(const T& var)
{
	if(isReadable())
		throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "pas d'ecriture en mode lecture");
	file<<var<<endl;
}
template <typename T>
T XmlFileSerializer<T>::read()
{
	if(isWritable())
		throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "pas de lecture en mode ecriture");
	string line;
	streampos pos= file.tellg();
	string end = "</" + getCollectionName() + ">";
	file>>line;
	if(line==end)
	{
		cout<<"fin"<<endl;
		throw XmlFileSerializerException(XmlFileSerializerException::END_OF_FILE, "fin du fichier");
	}
	file.seekg(pos);
	T type;
	file>>type;
	return type;
}
template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer()
{
	if(isWritable())
		file<<"</"<<getCollectionName()<<">"<<endl;
	file.close();
}