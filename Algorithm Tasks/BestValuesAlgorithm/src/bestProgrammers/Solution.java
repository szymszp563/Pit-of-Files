package bestProgrammers;

public class Solution {
	
	public int solution1(int[] A, int[] B, int F) {

		final int leng = A.length;
		final int numFronts = F;
		final int numBacks = leng - F;
		int result = 0; // final result

		int[] a = A;
		int[] b = B;

		int[] amb = new int[leng]; // array for A - B values

		/* A-B show us best choice */
		for (int i = 0; i < leng; i++) {
			amb[i] = a[i] - b[i];
		}

		//BubbleSort3Arrays.bubbleSort3Arrays(a, b, amb);
		
		MergeSort3Arrays.mergeSort3Arrays(amb, a, b, 0, leng - 1);//BEST CHOICE FOR BIG NUMBER OF DATA
		
		//QuickSort3Arrays.quickSort3Arrays(amb, a, b, 0, leng - 1);

		for (int i = 0; i < numFronts; i++) {
			result += a[i];
		}

		for (int i = numFronts; i < leng; i++) {
			result += b[i];
		}

		return result;

	}

}
