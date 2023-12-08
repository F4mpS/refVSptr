#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>


using dataANDdataDuplicatesCount = std::map<std::string, std::size_t>;
using dataContainer = std::pair<dataANDdataDuplicatesCount, std::size_t>;

void push(std::string str, std::vector<dataContainer> &dc, bool withReference)
{
    bool isNew = 1;
    for (auto& data : dc)
    {
        if (data.first.count(str))
        {
            isNew = 0;
            data.first[str] += 1;
        }
    }

    if (isNew)
    {
        if (withReference)
        {
            dataContainer& dataWithMinSize = dc.back();

            for (auto& data : dc)
            {
                if (data.second < dataWithMinSize.second)
                    dataWithMinSize = data;
            }

            dataWithMinSize.first.insert({ str, 1 });
            dataWithMinSize.second += 1;
        }
        else
        {
            dataContainer* dataWithMinSize = &dc.back();

            for (auto& data : dc)
            {
                if (data.second < dataWithMinSize->second)
                    dataWithMinSize = &data;
            }

            dataWithMinSize->first.insert({ str, 1 });
            dataWithMinSize->second += 1;
        }
    }
}

int main()
{
    std::vector<dataContainer> dc(2);

    //push("this", dc, 1);
    //push("is", dc, 1);
    //push("with", dc, 1);
    //push("reference", dc, 1);

    push("this", dc, 0);
    push("is", dc, 0);
    push("with", dc, 0);
    push("pointer", dc, 0);

    for (auto& i : dc)
        for (auto& m : i.first)
            std::cout << m.first << " " << m.second << std::endl;
}
