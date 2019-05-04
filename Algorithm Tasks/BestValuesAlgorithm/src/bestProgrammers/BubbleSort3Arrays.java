package bestProgrammers;

public class BubbleSort3Arrays {
	public static void bubbleSort3Arrays(int[] A, int[] B, int[] C) {
		int leng = C.length;
		int i, j, temp;
		boolean swapped;
		for (i = 0; i < leng - 1; i++) {
			swapped = false;
			for (j = 0; j < leng - i - 1; j++) {
				if (C[j] < C[j + 1]) {
					temp = C[j];
					C[j] = C[j + 1];
					C[j + 1] = temp;
					temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
					temp = B[j];
					B[j] = B[j + 1];
					B[j + 1] = temp;
					swapped = true;
				}
			}
			if (swapped == false) {
				break;
			}
		}
	}
}
