import profile_pic from './assets/profile.jpg';

function Card() {

  const name = "Aditya Gautam";

  return (
    <div className="card">
      <img className="card-img" src={profile_pic} alt="Profile Picture"></img>
      <h2 className="card-title">{name.toUpperCase()}</h2>
      <p className="card-text">I am a 2nd Year B.Tech Student at IIITD</p>
    </div>
  );
}

export default Card;
