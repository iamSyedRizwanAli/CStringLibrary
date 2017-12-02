//This CString library was completed by Syed Rizwan Ali on 15 April 2015
//This library is for educational purpose
//You can enhance it to your level of satisfaction

#include<iostream>
#include "CString.h"
using namespace std;

int CString :: getSize(const char * c)
{
	int i = 0;
	while(c[i] != '\0')
		i++;
	return i;
}

int CString :: getSize(const char * c) const
{
	int i = 0;
	while(c[i] != '\0')
		i++;
	return i;
}

void CString :: copyString(char * const dest, const char * const source)
{
	int i = 0;
	while(source[i] != '\0')
		dest[i] = source[i++];
	dest[i] = '\0';
}

void CString :: copyStringToNull(char * const dest, const char * const source)
{
	int i = 0;
	while(source[i] != '\0')
		dest[i++] = source[i];
}

int CString :: countAlike(const char ch)
{
	int count = 0, i = 0;
	while(i < size)
	{
		if(data[i] == ch)
			count++;
		i++;
	}
	return count;
}

int CString :: countAlikeStrings(const char * const oldChar)
{
	int str2Size = getSize(oldChar);
	int count = 0, count2 = 0, j = 0, k, l = 0;
	int i = 0;
	while(i < size)
	{
		if(data[i] == oldChar[j])
		{
			while(data[i] == oldChar[j])
			{
				k = i;
				while(l < str2Size && data[i]==oldChar[j])
				{
					count++;
					j++;
					i++;
					l++;
				}
				if(count == str2Size)
				{
					count2++;
				}
				j = 0;
				l = 0;
				count = 0;
			}
		}
		i++;
	}
	return count2;
}

int CString :: countTheCharB4anyDelim(const CString & c, const char * const delim)
{
	int strLength = c.getLength();
	int delimLength = getSize(delim);

	int i = 0, j = 0;
	bool flag = true;
	while(i < strLength && flag == true)
	{
		while(j < delimLength && flag == true)
		{
			if(c.data[i] != delim[j])
			{
				j++;
			}
			else
				flag = false;
		}
		i++;
		j = 0;
	}
	return i-1;
}

void CString :: deleteStr(char * str)
{
	delete [] str;
	str = 0;
}

CString :: CString()
{
	size = 0;
	data = 0;
}

CString :: CString(const char c)
{
	size = 2;
	data = new char [size];
	data[0] = c;
	data[1] = '\0';
}

CString :: CString(const char * const c)
{
	size = getSize(c);
	data = new char[size + 1];
	int i = 0;
	copyString(data,c);
}

int CString :: getLength()
{
	return getSize(data);
}

int CString :: getLength() const
{
	return getSize(data);
}

void CString :: display() const
{
	if(data)
		cout << data;
}

int CString :: find(const char * subStr, int start)
{
	int str2Size = getSize(subStr);
	int count = 0, j = 0, k, l = 0;
	int i = start;

	while(i < size)
	{
		if(data[i] == subStr[j])
		{
			k = i;
			while(l < str2Size && data[k]==subStr[j])
			{
				count++;
				j++;
				k++;
				l++;
			}
			if(count == str2Size)
				return i;
			else
				j = 0;
		}
		i++;
	}
	return -1;
}

int CString :: find(const char ch, int start)
{
	int i = start;
	while(i < size)
	{
		if(data[i] == ch)
				return i;
		i++;
	}
	return -1;
}

int CString :: isEmpty()
{
	if(data)
		return 1;
	return 0;
}

void CString :: input()
{
	char input[100];
	cin.getline(input,100);

	int siz3 = getSize(input);
	data = new char [siz3 + 1];

	size = siz3;
	copyString(data,input);
}

const char & CString :: at(int index) const
{
	if(index < size && index >= 0)
		return data[index];
	exit(0);
}

char & CString :: at(int index)
{
	if(index < size && index >= 0)
		return data[index];
	exit(0);
}

CString :: ~CString()
{
	if(data)
	{
		delete [] data;
		data = 0;
		size = 0;
	}
}

int CString :: insert(const int index, const char ch)
{
	char* temp = new char [size+1];
	int i = 0, j = 0, k = 0;

	while(i < size+1 && k < size)
	{
		if(i == index)
		{
			temp[i] = ch;
			i++;
		}
		else
		{
			temp[i] = data[k];
			i++;
			k++;
		}
	}
	temp[i] = '\0';
	size += 1;
	delete [] data;

	data = temp;
	temp = 0;

	return size;
}

int CString :: insert(const int index, const char * const subStr)
{
	int size1 = getSize(subStr);

	int newSize = size + size1;

	char* temp = new char [newSize + 1];
	int i = 0, j = 0, k = 0;

	while(i < newSize && k < size)
	{
		if(i == index)
		{
			while(j < size1)
			{
				temp[i] = subStr[j];
				i++;
				j++;
			}
		}
		else
		{
			temp[i] = data[k];
			i++;
			k++;
		}
	}
	temp[newSize] = '\0';

	delete [] data;
	data = temp;
	temp = 0;

	return size;
}

int CString :: remove(const int index, int count)
{
	if(index >= 0 && count < size)
	{
		int i = 0, k = 0, j = 0;
		char * temp = new char [size - count + 1];

		while(i < size-count && k < size)
			{
			if(k == index)
			{
				while(j < count)
				{
					k++;
					j++;
				}
			}
			else
			{
				temp[i] = data[k];
				i++;
				k++;
			}
		}
		temp[i] = '\0';
		size -= count;
		delete [] data;

		data = temp;
		temp = 0;

		return size;
	}
	return -1;
}

int CString :: remove(const char ch)
{
	int count = 0, i = 0, k =0 ;
	count = countAlike(ch);
	char * temp = new char [size-count+1];
	while(i < size-count && k < size)
	{
		if(data[k] == ch)
		{
			k++;
		}
		else
		{
			temp[i] = data[k];
			i++;
			k++;
		}
	}
	temp [i] = '\0';
	size -= count;

	delete [] data;
	data = temp;
	temp = 0;

	return count;
}

void CString :: replace(const char ch)
{
	int i = 0;

	while(i < size)
	{
		data[i] = ch;
		i++;
	}
}

int CString :: replace(const char oldChar,const char newChar)
{
	int count = countAlike(oldChar), i = 0;
	while(i < size)
	{
		if(data[i] == oldChar)
			data[i] = newChar;
		i++;
	}
	return count;
}

int CString :: replace(const char * oldChar, const char * newChar)
{
	int sizeOfOldChar = getSize(oldChar);
	int sizeOfNewChar = getSize(newChar);
	int countOfStrings = countAlikeStrings(oldChar);
	int extraSize;

	if(sizeOfOldChar > sizeOfNewChar)
		extraSize = (sizeOfOldChar - sizeOfNewChar) * countOfStrings;
	else
		extraSize = (sizeOfNewChar - sizeOfOldChar) * countOfStrings;

	int newSize = size + extraSize;

	char * temp = new char [newSize + 1];

	int i = 0, j = 0, l = 0, k = 0, count = 0, m = 0;

	while(i < size)
	{
		if(data[i] == oldChar[j])
		{
			k = i;
			while(data[k] == oldChar[j] && j < sizeOfOldChar)
			{
				count++;
				j++;
				k++;
			}
			j = 0;
			if(count == sizeOfOldChar)
			{
				i+= sizeOfOldChar;
				while(m < sizeOfNewChar)
				{
					temp[l] = newChar[m];
					l++;
					m++;
				}
				m = 0;
			}
			else
			{
				temp[l] = data[i];
				l++;
				i++;
			}
			count = 0;
		}
		else
		{
			temp[l] = data[i];
			l++;
			i++;
		}
	}
	temp[newSize] = '\0';
	delete [] data;
	size = newSize;

	data = temp;
	temp = 0;

	return countOfStrings;
}

void CString :: trim()
{
	trimLeft();
	trimRight();
}

void CString :: trimRight()
{
	int s = 0, i2 = size;
	while(data[i2--] <= 32)
	{
		s++;
	}

	int sizeHalf = size - s;
	sizeHalf /= 2;
	int i = sizeHalf;
	int count = 0;
	while(i < size)
	{
		if(data[i] == 32)
			count++;
		i++;
	}

	char * temp = new char [size - count + 1];

	i = 0;
	int j = 0;
	while(i < sizeHalf)
	{
		temp[j] = data[i];
		j++;
		i++;
	}
	while(j < size - count + 1)
	{
		if(data[i] == 32)
			i++;
		else
		{
			 temp[j] = data[i];
			 i++;
			 j++;
		}
	}
	size = size - count;
	temp[size] = '\0';
	
	delete [] data;
	data = temp;

	temp = 0;
}

void CString :: trimLeft()
{
	int s = 0, i2 = 0;
	while(data[i2++] <= 32)
	{
		s++;
	}

	int sizeHalf = (size - s) % 2 == 0? (size - s)/2 : (size - s)/2 + 1;
	int i = s;
	int count = 0;
	while(i < sizeHalf)
	{
		if(data[i] == 32)
			count++;
		i++;
	}
	i -= count;

	char * temp = new char [(size - count) + 1];

	int  j = 0;
	while(i < sizeHalf)
	{
		if(data[i] == 32)
		{
			i++;
		}
		else
		{
			temp[j] = data[i];
			i++;
			j++;
		}
	}
	while(j < size-count + 1)
	{
		temp[j] = data[i];
		i++;
		j++;
	}
	delete [] data;		
	size = size - count - s;
	temp[size] = '\0';
	data = temp;
	temp = 0;
}

void CString :: makeUpper()
{
	int i = 0;
	while(data[i] != '\0')
	{
		if(data[i] >= 'a' && data[i] <= 'z')
			data[i] -= 32;
		i++;
	}
}

void CString :: makeLower()
{
	int i = 0;
	while(data[i] != '\0')
	{
		if(data[i] >= 'A' && data[i] <= 'Z')
			data[i] += 32;
		i++;
	}
}

void CString :: reverse()
{
	char * temp = new char [size+1];
	int sizeOfString = size - 1;
	int i = sizeOfString, j = 0;
	while(i >= 0)
	{
		temp[j] = data[i];
		j++;
		i--;
	}
	temp[size] = '\0';
	delete [] data;
	data = temp;
	temp = 0;
}

void CString :: reSize(int add)
{
	if(add == 0)
		return;
	size = size + add;

	char * temp = new char [size];

	copyString(temp, data);
	delete [] data;

	data = new char [size+1];
	copyStringToNull(data,temp);

	int i;
	for(i = size-add-1 ; i < size ; i++)
		data[i] = 32;
	data[i] = '\0';
	size++;

	delete []temp;
}

void CString :: concatEqual(char * s2)
{
	int newSize = this->size + getSize(s2);
	char * temp = new char [newSize + 1];
	int i = 0;

	copyStringToNull(temp, this->data);
	i = getLength();
	int j = 0;

	while(i < newSize)
	{
		temp[i++] = s2[j++];
	}
	temp[i] = '\0';

	delete [] data;
	data = temp;
	temp = 0;

	size = newSize;
}

void CString :: concatEqual(const CString & s)
{
	concatEqual(s.data);
}

int CString :: isEqual(const char * const c)
{
	int count = 0;
	while(data[count] != '\0' && c[count] != '\0' && data[count]-c[count] == 0)
	{
		count++;
	}

	if(data[count] == '\0' && c[count] == '\0')
	{
		int i = 0, sumOfdata = 0, sumOfC = 0;
		while(data[i] != '\0')
		{
			sumOfdata += data[i];
			sumOfC += c[i];
		}
		if(sumOfC > sumOfdata)
			return -1;
		if(sumOfdata > sumOfC)
			return 1;
		return 0;
	}

	if(data[count] > c[count])
		return 1;
	else
		return -1;

	return -1;
}

int CString :: IsEqual(const CString & str)
{
	return isEqual(str.data);
}

CString :: CString(CString & c2)
{
	int  i = 0;
	this -> size = c2.size+1;
	this -> data = new char [size];
	copyString(this -> data, c2.data);
}

CString CString :: left(int count)
{
	CString freshCopy;

	if(!data)
		return freshCopy;

	int s = 0, i2 = 0;
	while(data[i2++] <= 32)
	{
		s++;
	}

	int slength = (getLength() - s)/2;
	int sizeForFreshCopy = count > slength ? slength : count;
	sizeForFreshCopy += 1;

	freshCopy.size = sizeForFreshCopy;
	freshCopy.data = new char [sizeForFreshCopy];
	int i = 0;

	while(i < count && i < slength)
		freshCopy.data[i] = this -> data[i++];
	freshCopy.data[i] = '\0';

	int k = i, j = 0;

	while(k < this -> size)
	{
		data[j] = data[k];
		j++;
		k++;
	}
	data[j] = '\0';

	return freshCopy;
}

CString CString :: right(int count)
{
	CString freshCopy;
	
	if(!data)
		return freshCopy;

	int s = 0, i2 = size;
	while(data[i2--] <= 32)
	{
		s++;
	}

	int size2 = getLength();
	int halfSize = (size2 - s) / 2;
	int size1 = halfSize - count;

	freshCopy.size = size1 > 0 ? count : halfSize;

	freshCopy.data = new char [freshCopy.size + 1];

	int i = size2-freshCopy.size + 1, j = 0;
	while(i < this -> size)
	{
		freshCopy.data[j] = data[i];
		i++;
		j++;
	}
	freshCopy.data[j] = '\0';

	data[size2 - freshCopy.size + 1] = '\0';

	return freshCopy;
}

CString CString :: concat(const CString & c2)
{
	if(!data && !c2.data)
		return data;

	CString concated;

	int size1 = getSize(this -> data);
	int size2 = getSize(c2.data);
	concated.size = size1 + size2 + 1;

	concated.data = new char [concated.size];

	copyStringToNull(concated.data,this -> data);

	int i = size1;

	int j = 0;

	while(i < concated.size)
	{
		concated.data[i] = c2.data[j];
		i++;
		j++;
	}

	concated.data[concated.size - 1] = '\0';
	return concated;
}

CString CString :: concat(const char * const c2)
{
	if(!c2)
		return data;

	CString concated;
	concated.size = getSize(this -> data) + getSize(c2) + 1;
	concated.data = new char [concated.size];
	copyStringToNull(concated.data,  this -> data);

	int i = getSize(this -> data);

	int j = 0;
	while(i < concated.size)
	{
		concated.data[i] = c2[j];
		i++;
		j++;
	}

	concated.data[concated.size - 1] = '\0';
	return concated;
}

CString CString :: tokenize(const char * const delim)
{
	CString token;

	if(!delim)
		return token;

	int sizeOfToken = countTheCharB4anyDelim(*this, delim);
	token.size = sizeOfToken + 1;
	token.data = new char [token.size];

	int i = 0, j = 0;

	while(i < sizeOfToken)
	{
		token.data[i] = this -> data[i];
		i++;
	} 

	token.data[i] = '\0';
	i++;
	while(i < size)
	{
		data[j] = data[i];
		j++;
		i++;
	}
	data[j] = '\0';
	size = j;
	return token;
}