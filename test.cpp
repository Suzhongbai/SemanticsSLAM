#include<iostream>
#include<map>
#include <vector>
# include  <algorithm>
#include<fstream>
#include <stdio.h>
#include <io.h>
using namespace std;



void writeAndSaveTxtFile(std::string& txt_path, std::map<int,std::vector<int>>& index_map)
{
    //ͷ�ļ���fstream
    std::ofstream o_file;
    //����ļ��Ѿ�������ɾ��
    //std::remove(txt_path.c_str());
    //ͷ�ļ���io.h
    if (_access(txt_path.c_str(), 0) == 0) //�ļ�������ɾ��
    {
        std::remove(txt_path.c_str());
    }
   

    o_file.open(txt_path.c_str(), std::ios::app);
    cout << "open the txt file and to write information" << endl;
    for (auto& p : index_map)
    {
        //cout << "frame" << p.first << endl;
        o_file << "frame " << p.first << " " << std::endl;
        o_file << "types ";
        for (auto& o : p.second)
        {
            o_file << o << " ";
        }
        o_file << endl;


    }
    o_file.close();
    o_file.flush();
    
}

void mapInsertAndFind(std::map<int, std::vector<int>> index_map)
{
	if (index_map.find(1) == index_map.end())
		index_map[1] = { 9,8 };

	//vector< int >::iterator iter = std::find(index_map[1].begin(), index_map[1].end(), 9); //���ص���һ��������ָ��
	auto iter = std::find(index_map[1].begin(), index_map[1].end(), 9); //���ص���һ��������ָ��

	if (iter != index_map[1].end()) {
		cout << "you" << endl;

	}
	else {
		cout << "no" << endl;
	}
//    vector< int >::iterator iter = std::find(v.begin(), v.end(), num_to_find); //���ص���һ��������ָ��
//    if (iter == v.end())
//        cout << "ERROR!" << endl;
//    else                //ע�������ָ�����Ԫ�صķ�ʽ��distance�÷�
//        cout << "the index of value " << (*iter) << " is " << std::distance(v.begin(), iter) << std::endl;
//    return  0;

	/*for (auto& p : index_map)
	{
		cout << p.first << endl;
		for (auto& s : p.second)
		{
			cout << s << endl;
		}

	}*/
}

int main() {
    std::map<int, std::vector<int>> index_map;
    index_map[2] = { 4,7,2 };
    mapInsertAndFind(index_map);
	std::string txt_path = "E:/semantics_offline_debug/dataset/ResultData/frame_type.txt";
    writeAndSaveTxtFile(txt_path, index_map);
	
	
}
