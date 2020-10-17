public class Solution
{
    public int Reverse(int x)
    {
        long answer = 0;
        int pop = 0;

        do
        {
            //pop
            pop = x % 10;
            x /= 10;

            //push
            answer = answer * 10 + pop;
        }
        while (x != 0);

        if (answer > Int32.MaxValue || answer < Int32.MinValue)
        {
            return 0;
        }
        else
        {
            return (int)answer;
        }
    }
}