#include <iostream>
#include <string>
#include <time.h>



struct Cell
{
public:
	int m_PosX, m_PosY;
	Cell() {}
	Cell(int x,int y) : m_PosX(x),m_PosY(y){
		CheckExceed();
	}
	void CheckExceed() {
		if (m_PosX > 39) {
			m_PosX = 39;
		}
		if (m_PosX < 0) {
			m_PosX = 0;
		}
		if (m_PosY > 39) {
			m_PosY = 39;
		}
		if (m_PosY < 0) {
			m_PosY = 0;
		}
	}
};


/*
int CheckCellNeighbours(const Cell& currentCell,bool theGrid[40][40]) //0 - up , 1 - down , 2 - left , 3 - right , -1 - error
{
	for (int y = -1; y <= 1; y++)
	{
		for (int x = -1; x <= 1; x++) {
			int posX = currentCell.m_PosX + x;
			int posY = currentCell.m_PosY + y;
			
			if (x == 0 && y == 0) {
				continue;
			}
			if (posX < 0 || posX > 39 || posY < 0 || posY > 39) {
				continue;
			}
			if (x == 0) {
				if (y < 0) {
					if (theGrid[posX][posY]) {
						return 0;
					}
				}
				if (y > 0) {
					if (theGrid[posX][posY]) {
						return 1;
					}
				}
			}
			if (y == 0) {
				if (x < 0) {
					if (theGrid[posX][posY]) {
						return 2;
					}
				}
				if (x > 0) {
					if (theGrid[posX][posY]) {
						return 3;
					}
				}
			}
		}
	}
}
*/

float DistanceBetweenTwoPoints(Cell firstCell, Cell secondCell) {
	float diffX = firstCell.m_PosX - secondCell.m_PosX;
	float diffY = firstCell.m_PosY - secondCell.m_PosY;
	return (sqrt(powf(diffX, 2) + (powf(diffY, 2))));
}


void GenerateMaze(bool baseGrid[40][40]) {

	//Generate 5 points

	Cell allCellPoint[5];
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		allCellPoint[i].m_PosX = (rand() % 38) + 1;
		allCellPoint[i].m_PosY = (rand() % 38) + 1;
	}
    
	// Algorithm
	int currentCellIndex = 0;
	Cell offsetPosition = allCellPoint[currentCellIndex];
	
	for (currentCellIndex = 0; currentCellIndex < 5; currentCellIndex++) {
		
	}

	for (currentCellIndex = 0; currentCellIndex < 5; currentCellIndex++)
	{ 	
		offsetPosition = allCellPoint[currentCellIndex];
		while (DistanceBetweenTwoPoints(allCellPoint[currentCellIndex], offsetPosition) < 5)
		{
			for (int y = -1; y <= 1; y++)
			{
				for (int x = -1; x <= 1; x++)
				{
					int xPos = offsetPosition.m_PosX + x;
					int yPos = offsetPosition.m_PosY + y;


					if (x == 0 && y == 0) {
						baseGrid[yPos][xPos] = false;
						continue;
					}
					if (xPos < 0 || xPos > 39 || yPos < 0 || yPos > 39) {
						continue;
					}

					if (baseGrid[yPos][xPos]) {
						offsetPosition = Cell(xPos, yPos);
						baseGrid[yPos][xPos] = false;

					}
				}
			}
		}
		

	}



	//To remove borders at the very edge 
	/*
	for (int y = 0; y < 40; y++) {
		for (int x = 0; x < 40; x++) {
			if (y == 0 || y == 39 || x == 0 || x == 39)
			{
				baseGrid[y][x] = true;
			}
		}
	}

	int currentX = 0;
	int currentY = 0;
	const int mazeIteration = 3;
	Cell allCurrentPoints[40];

	

	srand(time(NULL));
	


		for (int i = 0; i < mazeIteration; i++)
		{
			for (int z = 0; z < 40; z++) {
				currentX = (rand() % 38) + 2; // within the map itself
				currentY = (rand() % 38) + 2; 
				if ((z % 20) == 0) {
					
					currentY = 1;
				}				
				allCurrentPoints[z] = Cell(currentX, currentY);
			}
			for (int j = 1; j < 40; j++)
			{
				//this whole chunk of code calculates the difference between two points and clears all walls to reach
				// point[j-1]
				int diffX = allCurrentPoints[j].m_PosX - allCurrentPoints[j - 1].m_PosX; 
				int diffY = allCurrentPoints[j].m_PosY - allCurrentPoints[j - 1].m_PosY;
				if (diffX < 0) {
					for (int x = 0; x < std::abs(diffX); x++)
					{
						int thePosDiffX = allCurrentPoints[j].m_PosX + x;
						if (thePosDiffX > 39) {
							thePosDiffX = 39;
						}
						
						if (baseGrid[allCurrentPoints[j].m_PosY][thePosDiffX]) {
							//continue;
						}
						
						
						Cell cellToCheckCurrent = Cell(allCurrentPoints[j].m_PosX + x, allCurrentPoints[j].m_PosY);
						if (CheckCellNeighbours(cellToCheckCurrent, baseGrid) == 0 || CheckCellNeighbours(cellToCheckCurrent, baseGrid) == 1) {
							continue;
						}
						
						baseGrid[allCurrentPoints[j].m_PosY][thePosDiffX] = true;
					}
					allCurrentPoints[j].m_PosX = allCurrentPoints[j - 1].m_PosX;
				}
				if (diffY < 0) {
					for (int y = 0; y < std::abs(diffY); y++)
					{
						int thePosDiffY = allCurrentPoints[j].m_PosY + y;
						if (thePosDiffY > 39) {
							thePosDiffY = 39;
						}
						
						if (baseGrid[thePosDiffY][allCurrentPoints[j].m_PosX]) {
							//continue;
						}
						
						
						Cell cellToCheckCurrent = Cell(allCurrentPoints[j].m_PosX, allCurrentPoints[j].m_PosY + y);
						if (CheckCellNeighbours(cellToCheckCurrent, baseGrid) == 2 || CheckCellNeighbours(cellToCheckCurrent, baseGrid) == 3) {
							continue;
						}
						
						baseGrid[thePosDiffY][allCurrentPoints[j].m_PosX] = true;
					}
					allCurrentPoints[j].m_PosY = allCurrentPoints[j - 1].m_PosY;;
				}
				if (diffX > 0)
				{
					for (int x = 0; x < diffX; x++)
					{
						int thePosDiffX = (allCurrentPoints[j].m_PosX - x);
						if (thePosDiffX <= 0) {
							thePosDiffX = 0;
						}
						
						if (baseGrid[allCurrentPoints[j].m_PosY][thePosDiffX]) {
							//continue;
						}
						
						
						Cell cellToCheckCurrent = Cell(allCurrentPoints[j].m_PosX - x, allCurrentPoints[j].m_PosY );
						if (CheckCellNeighbours(cellToCheckCurrent, baseGrid) == 0 || CheckCellNeighbours(cellToCheckCurrent, baseGrid) == 1) {
							continue;
						}
						
						baseGrid[allCurrentPoints[j].m_PosY][thePosDiffX] = true;
					}

					allCurrentPoints[j].m_PosX = allCurrentPoints[j - 1].m_PosX;
				}
				if (diffY > 0)
				{
					for (int y = 0; y < diffY; y++)
					{

						int thePosDiffY = (allCurrentPoints[j].m_PosY - y);
						if (thePosDiffY <= 0) {
							thePosDiffY = 0;
						}
						
						if (baseGrid[thePosDiffY][allCurrentPoints[j].m_PosX]) {
							//continue;
						}
						
						/*
						Cell cellToCheckCurrent = Cell(allCurrentPoints[j].m_PosX, allCurrentPoints[j].m_PosY - y);
						if (CheckCellNeighbours(cellToCheckCurrent, baseGrid) == 2 || CheckCellNeighbours(cellToCheckCurrent, baseGrid) == 3) {
							continue;
						}
						
						baseGrid[thePosDiffY][allCurrentPoints[j].m_PosX] = true;
					}

					allCurrentPoints[j].m_PosY = allCurrentPoints[j - 1].m_PosY;
				}

				if (diffX == 0 || diffY == 0)
				{
					continue;
				}
			}


		}
	
		//std::cout << "X : " << currentX << "Y : " << currentY << std::endl;
		
	*/

}

