vector<int> idx(n);
        idx[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (A[i] >= A[idx[i + 1]])
            {
                idx[i] = i;
            }
            else
            {
                idx[i] = idx[i + 1];
            }
        }
        int i;
        for (int i = n - 1; i >= 0; i--)
        {
            if (A[i] < A[idx[i]])
            {
                swap(A[i], A[idx[i]]);
                break;
            }
        }
        if (i == 0)
        {
            sort(A.begin(), A.end());
        }