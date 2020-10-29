using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode_Master
{
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

    /*
    static void Main(string[] args)
    {
        int[] nums = { 1, 2, 3 };
        ShuffleArray obj = new ShuffleArray(nums);
        int[] param_1 = obj.Reset();
        foreach (int param in param_1)
        {
            Console.WriteLine(param);
        }
        int[] param_2 = obj.Shuffle();
        foreach (int param in param_2)
        {
            Console.WriteLine(param);
        }
    }
    */
}
