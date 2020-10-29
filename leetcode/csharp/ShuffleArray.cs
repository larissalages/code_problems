// Problem 670: https://leetcode.com/explore/interview/card/top-interview-questions-easy/98/design/670/
public class ShuffleArray
{
    int[] arrayOriginal;
    int[] arrayCopy;

    public ShuffleArray(int[] nums)
    {
        arrayOriginal = (int[])nums.Clone();
        arrayCopy = nums;
    }

    public int[] Reset()
    {
        return arrayOriginal;
    }
    public int[] Shuffle()
    {
        Random random = new Random();

        for (int i = 0; i < arrayCopy.Length; i++)
        {
            swapPlaces(i, random.Next(0, arrayCopy.Length));
        }
        return arrayCopy;
    }

    private void swapPlaces(int i, int j)
    {
        int temp = arrayCopy[i];
        arrayCopy[i] = arrayCopy[j];
        arrayCopy[j] = temp;
    }
}
