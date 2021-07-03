/*
*  Реализуйте обработку следующих операций над очередью:
*
*  WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
*  QUIET i: пометить i-го человека как успокоившегося;
*  COME k: добавить k спокойных человек в конец очереди;
*  COME -k: убрать k человек из конца очереди;
*  WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
*
*  Формат ввода
*  Количество операций Q, затем описания операций.
*
*  Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.
*
*  Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.
*
*  Формат вывода
*  Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокоящихся людей в очереди.
*/

#include <iostream>
#include <vector>

using namespace std;

void    call_come(vector<int>& line, int first_in_flag)
{
    int n;
    cin >> n;

    if (n > 0 && first_in_flag == 0)
        line.assign(n, 0);
    else if (n > 0 && first_in_flag != 0)
        line.resize(((line.size()) + n));
    else if (n < 0)
        line.resize(((line.size()) + n));
}

void    call_worry(vector<int>& line)
{
    int i;
    cin >> i;

    line[i] = 1;
}

void    call_quiet(vector<int>& line)
{
    int i;
    cin >> i;

    line[i] = 0;
}

void    call_worry_count(const vector<int>& line)
{
    int count = 0;

    for (auto i: line)
        if ( i == 1)
            count++;
    cout << count << endl;
}

int     main()
{
    vector<int> people_line(0);
    string cmd;
    int q;
    int first_in_flag = 0;
    
    cin >> q;

    while (q != 0)
    {
        cmd.clear();
        cin >> cmd;

        if (cmd == "COME")
        {
            call_come(people_line, first_in_flag);
            first_in_flag = 1;
        }
        else if (cmd == "WORRY")
            call_worry(people_line);
        else if (cmd == "QUIET")
            call_quiet(people_line);
        else if (cmd == "WORRY_COUNT")
            call_worry_count(people_line);
        else
            break;
        q--;
    }
    return 0;
}