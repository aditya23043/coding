import "./Card.css";

function Card({ workout, count, target, url }) {
  return (
    <>
      <div className="container">
        <h1>{workout}</h1>
        <h3>{count}</h3>
        <h4>Target Muscle: {target}</h4>
        <a href={url}>URL</a>
      </div>
    </>
  );
}

export default Card;
