#ifndef XMLFILESERIALIZER_H
#define XMLFILESERIALIZER_H
#include <fstream>
#include <string>
using namespace std;

template <typename T>

class XmlFileSerializer
{
private:
	fstream file;
	string filename;
	string collectionName;
	char mode;
public:
	XmlFileSerializer() = delete;
	~XmlFileSerializer();
	static const char READ;
	static const char WRITE;
	XmlFileSerializer(const string&, const char, const string& cn = "entites");
	XmlFileSerializer(const XmlFileSerializer&) = delete;
	bool isReadable();
	bool isWritable();
	string getFilename()const;
	string getCollectionName()const;
	void write(const T&);
	T read();
	XmlFileSerializer<T> operator=(const XmlFileSerializer<T>&)= delete;
};
#include "XmlFileSerializer.ipp"
#endif