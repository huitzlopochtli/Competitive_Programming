using System;
using NUnit.Framework;
using Solutons;

namespace Solutions.Test
{
    public class MergeSortTest
    {
        [Test]
        public void SortInPlaceTest()
        {
            int[] unSort = { 4, 2, 7, 5 };
            MergeSort.In_PlaceSort(unSort, 0, unSort.Length - 1);

            int[] sort = { 2, 4, 5, 7 };

            Assert.AreEqual(unSort, sort);

        }
    }
}
