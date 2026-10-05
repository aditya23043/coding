function highlightDartCode(codeElement) {

    const keywords = [
        'void', 'int', 'String', 'bool', 'double', 'var', 'final', 'class', 
        'return', 'if', 'else', 'for', 'while', 'import', 'true', 'false', 
        'print', 'const', 'main', 
        'async', 'await', 'dynamic', 'enum', 'extension', 'factory', 
        'get', 'set', 'late', 'mixin', 'null', 'operator', 'required', 
        'super', 'switch', 'this', 'throw', 'try', 'catch', 'finally', 
        'abstract', 'covariant', 'export', 'external', 'library', 'part', 
        'static', 'typedef'
    ];

    const colorMap = {
        // Type declarations (yellow)
        'void': '#d8a657',
        'int': '#d8a657',
        'String': '#d8a657',
        'bool': '#d8a657',
        'double': '#d8a657',
        'var': '#d8a657',
        'dynamic': '#d8a657',

        // Modifiers (orange)
        'final': '#e78a4e',
        'const': '#e78a4e',
        'static': '#e78a4e',
        'abstract': '#e78a4e',
        'late': '#e78a4e',
        'required': '#e78a4e',

        // Control flow (red)
        'class': '#ea6962',
        'return': '#ea6962',
        'if': '#ea6962',
        'else': '#ea6962',
        'for': '#ea6962',
        'while': '#ea6962',
        'switch': '#ea6962',
        'try': '#ea6962',
        'catch': '#ea6962',
        'finally': '#ea6962',
        'throw': '#ea6962',
        'enum': '#ea6962',
        'extension': '#ea6962',

        // Import/library related (purple)
        'import': '#d3869b',
        'library': '#d3869b',
        'part': '#d3869b',
        'export': '#d3869b',
        'external': '#d3869b',

        // Special values (purple)
        'true': '#d3869b',
        'false': '#d3869b',
        'null': '#d3869b',

        // Function/method related (green)
        'print': '#a9b665',
        'main': '#a9b665',
        'get': '#a9b665',
        'set': '#a9b665',

        // Other language constructs
        'async': '#d8a657',
        'await': '#d8a657',
        'factory': '#e78a4e',
        'mixin': '#ea6962',
        'operator': '#e78a4e',
        'super': '#d3869b',
        'this': '#d3869b',
        'covariant': '#d8a657',
        'typedef': '#ea6962'
    };

    let html = codeElement.textContent;

    // Split text into parts, preserving quotes
    const parts = html.split(/(".*?"|'.*?'|\/\/.*)/g);
    
    html = parts.map((part, index) => {
        // Odd indices are quotes, color them green
        if (index % 2 === 1) {
            // check for $
            // Check if it's a comment
            if (part.startsWith('//')) {
                return `<span style="color: #454545">${part}</span>`;
            }
            const interpolationRegex = /\$(\w+)/g;
            part = part.replace(interpolationRegex, (match, word) => 
                `<span style="color: #7daea3">${match}</span>`
            );
            return `<span style="color: #a9b665">${part}</span>`;
        }

        // For non-quote parts, highlight keywords
        keywords.forEach(keyword => {
            const regex = new RegExp(`\\b${keyword}\\b`, 'g');
            part = part.replace(regex, match => 
                `<span style="color: ${colorMap[match]}">${match}</span>`
            );
        });

        return part;
    }).join('');

    codeElement.innerHTML = html;
}

document.addEventListener('DOMContentLoaded', () => {
    // Use querySelectorAll to select ALL elements with .code class
    const codeElements = document.querySelectorAll('.code');
    
    // Iterate through each code element and apply highlighting
    codeElements.forEach(highlightDartCode);
});
