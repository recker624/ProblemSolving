/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function(columnNumber) {
    let codeA = 65; //ascii code for 'A'
    let title = '';

    while (columnNumber > 0) {
        columnNumber--;

        let remainder = Math.floor(columnNumber % 26);

        title += String.fromCharCode(codeA + remainder);

        columnNumber = Math.floor(columnNumber / 26);
    }

    return title.split('').reverse().join('');
};

convertToTitle(28);