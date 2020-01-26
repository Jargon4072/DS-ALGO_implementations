'''
Author: Chandan Dwivedi
Date: 04/02/2019

function to claculate amount of water stored in platform0
'''
import heapq
def WaterStoredInPlatform(height):
        height=height.tolist()
        m = len(height)
        if m == 0:
            return 0
        n = len(height[0])
        if n == 0:
            return 0

        visited = [[0] * n for _ in range(m)]
        water = 0
		# This array acts as a heap to help look up the minimum height seen so far
        min_height_lookup = []

		# Visit the boundary elements of the matrix
        for row in range(m):
            for column in range(n):
                if row == 0 or column == 0 or row == m - 1 or column == n - 1:
					# Mark the entry as having been visited
                    visited[row][column] = 1
					# Push the height along with the row, column indices on to the heap
                    heapq.heappush(min_height_lookup, (height[row][column], row, column))

		# Iterate over the heap and successively check the neighbors of the minimum height elements
		# Thus, we start at the boundary of the matrix and keep going into the inner layers
        while min_height_lookup:
            min_height, min_row, min_column = heapq.heappop(min_height_lookup)

			# Check the neighbors of each element
            for r, c in ((min_row + 1, min_column), (min_row - 1, min_column), (min_row, min_column + 1), (min_row, min_column - 1)):
                if 0 <= r <= m - 1 and 0 <= c <= n - 1 and not visited[r][c]:

					# If the neighbor is of lesser height than that of the current element,
					# water will collect there. Else it will flow away.
					# For each neighbor, the water level will be equal to the difference between the heights
                    #water += max(0, min_height - height[r][c])

					# Store the taller of the heights betwen the current element and the neighbor on the heap
                    #new_height = max(min_height, height[r][c])
                    #heapq.heappush(min_height_lookup, (new_height, r, c))

					# Mark the neighbor as having been visited
                    # check if drainage is present or not
                    #visited[r][c] = 1
                    if ((height[r][c] is not 0) and (height[r+1][c] is not 0) and (height[r][c+1] is not 0) and (height[r+1][c+1] is not 0) and (height[r+1][c-1] is not 0)):
                        #print("yes")
                        water += max(0, min_height - height[r][c])
                        new_height = max(min_height, height[r][c])
                        heapq.heappush(min_height_lookup, (new_height, r, c))
                        visited[r][c] = 1

                    if (height[r][c]==0):
                            if(height[r+1][c]!=min_height):
                                height[r+1][c]=0
                            if(height[r+1][c+1]!=min_height):
                                height[r+1][c+1]=0
                            if(height[r][c+1]!=min_height):
                                height[r][c+1]=0
                            if(height[r+1][c-1]!=min_height):
                                height[r+1][c-1]=0
                            if(height[r-1][c]!=min_height):
                                height[r-1][c]=0
                            if(height[r-1][c-1]!=min_height):
                                height[r-1][c-1]=0
                            if(height[r][c-1]!=min_height):
                                height[r][c-1]=0
                            if(height[r-1][c+1]!=min_height):
                                height[r-1][c+1]=0

        return water