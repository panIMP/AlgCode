bool 
findNumInMatrix(int* matrix, int rows, int cols, int number)
{
	bool found = false;

    if (matrix != nullptr && rows > 0 && cols > 0)
	{
		int row = 0;
		int column = cols - 1;

		while (column >= 0 && row < rows)
		{
			int curNum = matrix[row * cols + column];
			if (curNum == number)
			{
				return true;
			}
			else if (curNum > number)
			{
				--column;
			}
			else
				++row;
		}
	}

	return found;
}
