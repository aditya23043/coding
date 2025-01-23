function Content() {

  const content_1 = "Vim";
  const content_2 = "Neovim";
  const content_3 = "Emacs";
  const content_4 = "Sublime";

  return (
    <ul>
      <li>{content_1.toUpperCase()}</li>
      <li>{content_2.toLowerCase()}</li>
      <li>{content_3.length}</li>
      <li>{content_4}</li>
    </ul>
  );
}

export default Content;
