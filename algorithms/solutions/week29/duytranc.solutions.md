# Problem 2
#### [ELEVTRBL - Elevator Trouble](https://www.spoj.com/problems/ELEVTRBL/)
```cs
private string SolveElevatorTrouble(int floors, int start, int goal, int up, int down)
{
	var stepCounts = new int[floors + 1];

	for (int i = 0; i <= floors; i++)
	{
		stepCounts[i] = -1;
	}

	var queue = new Queue<int>();
	queue.Enqueue(start);
	stepCounts[start] = 0;
	var result = -1;

	while (queue.Any())
	{
		var currentFloor = queue.Dequeue();
		if (stepCounts[goal] != -1)
		{
			result = stepCounts[goal];
			break;
		}
		var upFloor = currentFloor + up;
		if (upFloor <= floors && stepCounts[upFloor] == -1)
		{
			stepCounts[upFloor] = stepCounts[currentFloor] + 1;
			queue.Enqueue(upFloor);
		}

		var downFloor = currentFloor - down;
		if (downFloor >= 1 && stepCounts[downFloor] == -1)
		{
			stepCounts[downFloor] = stepCounts[currentFloor] + 1;
			queue.Enqueue(downFloor);
		}
	   
	}
	return result == -1 ? "use the stairs" : result.ToString();
}
```


