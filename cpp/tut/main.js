function highlightDartCode(codeElement) {
    const keywords = [
        // Data types
        'int', 'char', 'bool', 'void', 'float', 'double', 
        'short', 'long', 'unsigned', 'signed', 'string', 
        
        // Control flow
        'if', 'else', 'switch', 'case', 'default', 
        'for', 'while', 'do', 'break', 'continue', 'return',
        
        // Object-oriented keywords
        'class', 'struct', 'enum', 'namespace', 
        'public', 'private', 'protected', 
        
        // Other important keywords
        'const', 'static', 'virtual', 'inline', 
        'template', 'typename', 'auto', 'extern', 
        'using', 'new', 'delete', 'nullptr',
        
        // C++ specific
        'true', 'false', 'this', 'friend', 'mutable'
    ];

    const colorMap = {
        // Blue for data types
        'int': '#569CD6',
        'char': '#569CD6',
        'bool': '#569CD6',
        'void': '#569CD6',
        'float': '#569CD6',
        'double': '#569CD6',
        'short': '#569CD6',
        'long': '#569CD6',
        'unsigned': '#569CD6',
        'signed': '#569CD6',
        'string': '#569CD6',

        // Purple for control flow and OOP keywords
        'if': '#C678DD',
        'else': '#C678DD',
        'switch': '#C678DD',
        'case': '#C678DD',
        'default': '#C678DD',
        'for': '#C678DD',
        'while': '#C678DD',
        'do': '#C678DD',
        'break': '#C678DD',
        'continue': '#C678DD',
        'return': '#C678DD',
        'class': '#C678DD',
        'struct': '#C678DD',
        'enum': '#C678DD',
        'namespace': '#C678DD',
        'public': '#C678DD',
        'private': '#C678DD',
        'protected': '#C678DD',

        // Other keywords
        'const': '#C678DD',
        'static': '#C678DD',
        'virtual': '#C678DD',
        'inline': '#C678DD',
        'template': '#C678DD',
        'typename': '#C678DD',
        'auto': '#C678DD',
        'extern': '#C678DD',
        'using': '#C678DD',
        'new': '#C678DD',
        'delete': '#C678DD',
        'nullptr': '#C678DD',
        'true': '#C678DD',
        'false': '#C678DD',
        'this': '#C678DD',
        'friend': '#C678DD',
        'mutable': '#C678DD'
    };


    let html = codeElement.textContent;

    // Updated regex to better handle include statements and angle brackets
    const parts = html.split(/(".*?"|'.*?'|\/\/.*|#include\s*<[^>]*>)/g);

    html = parts.map((part, index) => {
        // Odd indices are quotes, comments, or include statements
        if (index % 2 === 1) {
            // Check if it's a comment
            if (part.startsWith('//')) {
                return `<span style="color: #6A9955">${part}</span>`;
            }
            
            // Check if it's an include statement
            if (part.startsWith('#include')) {
                return `<span style="color: #C678DD">${part}</span>`;
            }
            
            // Regular string literals
            return `<span style="color: #CE9178">${part}</span>`;
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
    const codeElements = document.querySelectorAll('.code');
    codeElements.forEach(highlightCppCode);
});
