function highlightDartCode(codeElement) {
    const keywords = [
        'void', 'int', 'String', 'var', 'final', 'class', 
        'return', 'if', 'else', 'for', 'while', 'import', 'true', 'false'
    ];

    const colorMap = {
        'void': '#569CD6',
        'int': '#569CD6',
        'String': '#569CD6',
        'var': '#569CD6',
        'final': '#569CD6',
        'class': '#C678DD',
        'return': '#C678DD',
        'if': '#C678DD',
        'else': '#C678DD',
        'for': '#C678DD',
        'while': '#C678DD',
        'import': '#C678DD',
        'true': '#C678DD',
        'false': '#C678DD'
    };

    let html = codeElement.textContent;

    // Split text into parts, preserving quotes
    const parts = html.split(/(".*?"|'.*?'|\/\/.*)/g);
    
    html = parts.map((part, index) => {
        // Odd indices are quotes, color them green
        if (index % 2 === 1) {
            // Check if it's a comment
            if (part.startsWith('//')) {
                return `<span style="color: #454545">${part}</span>`;
            }
            return `<span style="color: #2ecc71">${part}</span>`;
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
    const codeElement = document.querySelector('.code');
    highlightDartCode(codeElement);
});

