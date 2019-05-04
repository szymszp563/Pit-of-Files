package bestProgrammers;

public class MergeSort3Arrays {

	/*
	 * Merges two subarrays of mainArr[], arr2[] and arr3[]. First subarray is
	 * arr[l..m], arr2[l..m], arr3[l..m] Second subarray is mainArr[m+1..r],
	 * arr2[l..m], arr3[l..m]
	 */
	private static void merge(int mainArr[], int arr2[], int arr3[], int startInd, int midInd, int endInd) {
		// Find sizes of two subarrays to be merged
		int n1 = midInd - startInd + 1;
		int n2 = endInd - midInd;

		/* Create temp arrays */
		int L[] = new int[n1];
		int L2[] = new int[n1];
		int L3[] = new int[n1];
		int R[] = new int[n2];
		int R2[] = new int[n2];
		int R3[] = new int[n2];

		/* Copy data to temp arrays */
		for (int i = 0; i < n1; ++i) {
			L[i] = mainArr[startInd + i];
			L2[i] = arr2[startInd + i];
			L3[i] = arr3[startInd + i];
		}

		for (int j = 0; j < n2; ++j) {
			R[j] = mainArr[midInd + 1 + j];
			R2[j] = arr2[midInd + 1 + j];
			R3[j] = arr3[midInd + 1 + j];
		}

		/* Merge the temp arrays */

		// Initial indexes of first and second subarrays
		int i = 0, j = 0;

		// Initial index of merged subarry array
		int k = startInd;
		while (i < n1 && j < n2) {
			if (L[i] >= R[j]) // reverse sort
			{
				mainArr[k] = L[i];
				arr2[k] = L2[i];
				arr3[k] = L3[i];
				i++;
			} else {
				mainArr[k] = R[j];
				arr2[k] = R2[j];
				arr3[k] = R3[j];
				j++;
			}
			k++;
		}

		/* Copy remaining elements of L[] if any */
		while (i < n1) {
			mainArr[k] = L[i];
			arr2[k] = L2[i];
			arr3[k] = L3[i];
			i++;
			k++;
		}

		/* Copy remaining elements of R[] if any */
		while (j < n2) {
			mainArr[k] = R[j];
			arr2[k] = R2[j];
			arr3[k] = R3[j];
			j++;
			k++;
		}
	}

	/*
	 * Main function that sorts mainArr[startInd..endInd] and to maintain indexes sorting arr2[]
	 * and arr3[] with mainArr[]. arr2[] and arr3[] are not necessarily sorted from
	 * highest value to lowest they change values at same index as mainArr[] which
	 * is really sorted
	 */
	public static void mergeSort3Arrays(int mainArr[], int arr2[], int arr3[], int startInd, int endInd) {
		if (startInd < endInd) {
			// Find the middle point
			int middle = (startInd + endInd) / 2;

			// Sort first and second halves
			mergeSort3Arrays(mainArr, arr2, arr3, startInd, middle);
			mergeSort3Arrays(mainArr, arr2, arr3, middle + 1, endInd);

			// Merge the sorted halves
			merge(mainArr, arr2, arr3, startInd, middle, endInd);
		}
	}
}
