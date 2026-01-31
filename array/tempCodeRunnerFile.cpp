Solution s;
    vector<vector<int>> ans = s.generate(5);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }