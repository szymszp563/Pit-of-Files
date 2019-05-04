package bestProgrammers;

public class QuickSort3Arrays {
	private static int partition(int mainArr[], int arr2[], int arr3[], int startingInd, int endingInd) {
		int pivot = mainArr[endingInd];
		int i = (startingInd - 1); // index of smaller element
		for (int j = startingInd; j < endingInd; j++) {
			// If current element is smaller than or
			// equal to pivot
			if (mainArr[j] >= pivot) // reverse
			{
				i++;

				// swap arr[i] and arr[j]
				int temp = mainArr[i];
				mainArr[i] = mainArr[j];
				mainArr[j] = temp;

				temp = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = temp;

				temp = arr3[i];
				arr3[i] = arr3[j];
				arr3[j] = temp;
			}
		}

		// swap arr[i+1] and arr[endingInd] - place pivot to the right place
		int temp = mainArr[i + 1];
		mainArr[i + 1] = mainArr[endingInd];
		mainArr[endingInd] = temp;

		temp = arr2[i + 1];
		arr2[i + 1] = arr2[endingInd];
		arr2[endingInd] = temp;

		temp = arr3[i + 1];
		arr3[i + 1] = arr3[endingInd];
		arr3[endingInd] = temp;

		return i + 1;
	}

	/*
	 * Main function that sorts mainArr[l..r] and to maintain indexes sorting arr2[]
	 * and arr3[] with arr[] arr2[] and arr3[] are not necessarily sorted from
	 * highest value to lowest they change values at same index as mainArr[] which
	 * is really sorted
	 */
	public static void quickSort3Arrays(int mainArr[], int arr2[], int arr3[], int startingInd, int endingInd) {
		if (startingInd < endingInd) {
			/*
			 * pi is partitioning index, arr[pi] is now at right place
			 */
			int pi = partition(mainArr, arr2, arr3, startingInd, endingInd);

			// Recursively sort elements before
			// partition and after partition
			quickSort3Arrays(mainArr, arr2, arr3, startingInd, pi - 1);
			quickSort3Arrays(mainArr, arr2, arr3, pi + 1, endingInd);
		}
	}
}
