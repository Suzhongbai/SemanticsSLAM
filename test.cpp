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
    //头文件是fstream
    std::ofstream o_file;
    //如果文件已经存在则删除
    //std::remove(txt_path.c_str());
    //头文件是io.h
    if (_access(txt_path.c_str(), 0) == 0) //文件存在则删除
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

	//vector< int >::iterator iter = std::find(index_map[1].begin(), index_map[1].end(), 9); //返回的是一个迭代器指针
	auto iter = std::find(index_map[1].begin(), index_map[1].end(), 9); //返回的是一个迭代器指针

	if (iter != index_map[1].end()) {
		cout << "you" << endl;

	}
	else {
		cout << "no" << endl;
	}
//    vector< int >::iterator iter = std::find(v.begin(), v.end(), num_to_find); //返回的是一个迭代器指针
//    if (iter == v.end())
//        cout << "ERROR!" << endl;
//    else                //注意迭代器指针输出元素的方式和distance用法
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

