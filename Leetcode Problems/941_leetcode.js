/**
 * @param {number[]} arr
 * @return {boolean}
 */
var validMountainArray = function(arr) {
  //There should be two main parts in the array for it to be a valid mountain array
  //Strictly increasing part and strictly decreasing part.
  let i = 0;

  if (arr.length < 3)
    return false;

  while ( i < (arr.length - 1) && arr[i] < arr[i + 1] ) i++;

  if (i == 0 || i == arr.length - 1) return false;

  while (i < (arr.length - 1) && arr[i] > arr[i + 1]) i++;

  return (i == arr.length - 1);
};