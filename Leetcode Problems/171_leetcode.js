/**
 * @param {string} columnTitle
 * @return {number}
 */
var titleToNumber = function(columnTitle) {
    let num = 0;
    let length = 0;
    while(length < columnTitle.length) {
      num += (columnTitle.charCodeAt(length) - 65 + 1) * Math.pow(26, columnTitle.length - length - 1);
      length++;
    }
  return num;
};