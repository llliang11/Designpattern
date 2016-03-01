/*
 * Main.cpp
 *
 *  Created on: 2016/02/29
 *      Author: larry
 */
#include <stdio.h>

class File
{
public:
	virtual void dataProcess(void *pOutData, int *outSize)
	{
		printf("file process data ...\n");
	}
};

class DataProcess: public File
{
protected:
	File *component;
public:
	void setProcessComponent(File *pFile)
	{
		component = pFile;
	}

	virtual void dataProcess(void *pOutData, int *outSize)
	{
		if (component != NULL)
		{
			component->dataProcess(NULL, NULL);
		}
	}
};

class Demux: public DataProcess
{
public:
	virtual void dataProcess(void *pOutData, int *outSize)
	{
		DataProcess::dataProcess(NULL, NULL);
		printf("Demux process data ...\n");
	}
};

class Codec: public DataProcess
{
public:
	virtual void dataProcess(void *pOutData, int *outSize)
	{
		DataProcess::dataProcess(NULL, NULL);
		printf("Codec process data ...\n");
	}
};

class Sink: public DataProcess
{
public:
	virtual void dataProcess(void *pOutData, int *outSize)
	{
		DataProcess::dataProcess(NULL, NULL);
		printf("Sink process data ...\n");
	}
};

class Component: public DataProcess
{
public:
	virtual void dataProcess(void *pOutData, int *outSize)
	{
		DataProcess::dataProcess(NULL, NULL);
		printf("Component process data ...\n");
	}
};

int main(void)
{
	File *aviFile = new File();
	Demux *aviDemux = new Demux();
	Codec *h264 = new Codec();
	Sink *imageSink = new Sink();

	Component *com = new Component();

	aviDemux->setProcessComponent(aviFile);
	h264->setProcessComponent(aviDemux);
	com->setProcessComponent(h264);
	imageSink->setProcessComponent(com);
	imageSink->dataProcess(NULL, NULL);
	return 0;
}



