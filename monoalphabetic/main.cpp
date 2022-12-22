#include <iostream>
#include "helpers.h"
#include "additive.h"
#include "multiplicative.h"
#include "affine.h"
#include "keyword.h"
#include <future>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::string;
using namespace std::chrono;

// Assuming an alphabet of 26 letters (a-z)

int main()
{
  // Test helpers
  // std::cout << shift('a',3) << std::endl;
  // std::string m = "This is a message!";
  // cleanMessage(m);
  // std::cout << m << std::endl;
  // string k = "mathematics";
  // cleanKeyword(k);
  // cout << k << endl;

  // Test keyword
  // string keyword = "mathematics";
  // char keyletter = 'f';
  // string message = "abcdefghijklmnopqrstuvwxyz";
  // cout << "Keyword cipher of message \"" << message << "\" with keyword " << keyword << " and keyletter " << keyletter << endl;
  // string ci = keywordEncipher(message, keyword, keyletter);
  // cout << ci << endl;
  // cout << keywordDecipher(ci, keyword, keyletter) << endl << endl;

  // Test additive
  int key = 13;
  string message = "Dear Mich, This letter utilizes a number of cipher techniques from the book you lent me period I am very excited to get to work enciphering it period I regret that I did not start earlier period It took time for me to really understand that math could be enjoyed outside of school period Not just in an academic way like watching numberphile videos but in a practical and active way period Cryptography is fun period I enjoy learning and implementing all these different walls people have erected to protect their messages and all the ways other people have tried to tear them down period If you are reading this you know that the first section was a Caesar cipher or what the book calls an additive monoalphabetic cipher period The next section will be enciphered using a certain type of special square period I will figure out a way to transmit the key to you securely period If I put it in this section of the letter then it would be too easy for an interceptor to decode it given that I have just drastically narrowed down possibilities for the next enciphering method period Moby-Dick; or, The Whale is an 1851 novel by American writer Herman Melville. The book is the sailor Ishmael's narrative of the obsessive quest of Ahab, captain of the whaling ship Pequod, for revenge against Moby Dick, the giant white sperm whale that on the ship's previous voyage bit off Ahab's leg at the knee. A contribution to the literature of the American Renaissance, Moby-Dick was published to mixed reviews, was a commercial failure, and was out of print at the time of the author's death in 1891. Its reputation as a Great American Novel was established only in the 20th century, after the 1919 centennial of its author's birth. William Faulkner said he wished he had written the book himself,[1] and D. H. Lawrence called it one of the strangest and most wonderful books in the world and the greatest book of the sea ever written.[2] Its opening sentence, Call me Ishmael, is among world literature's most famous.[3]Melville began writing Moby-Dick in February 1850 and finished 18 months later, a year after he had anticipated. Melville drew on his experience as a common sailor from 1841 to 1844, including on whalers, and on wide reading in whaling literature. The white whale is modeled on a notoriously hard-to-catch albino whale Mocha Dick, and the book's ending is based on the sinking of the whaleship Essex in 1820. The detailed and realistic descriptions of whale hunting and of extracting whale oil, as well as life aboard ship among a culturally diverse crew, are mixed with exploration of class and social status, good and evil, and the existence of God. The book's literary influences include Shakespeare, Carlyle and the Bible. In addition to narrative prose, Melville uses styles and literary devices ranging from songs, poetry, and catalogs to Shakespearean stage directions, soliloquies, and asides. In August 1850, with the manuscript perhaps half finished, he met Nathaniel Hawthorne and was deeply impressed by his Mosses from an Old Manse, which he compared to Shakespeare in its cosmic ambitions. This encounter may have inspired him to revise and deepen Moby-Dick, which is dedicated to Hawthorne, in token of my admiration for his genius.The book was first published (in three volumes) as The Whale in London in October 1851, and under its definitive title, Moby-Dick, or, The Whale, in a single-volume edition in New York in November. The London publisher, Richard Bentley, censored or changed sensitive passages; Melville made revisions as well, including a last-minute change of the title for the New York edition. The whale, however, appears in the text of both editions as Moby Dick, without the hyphen.[4] Reviewers in Britain were largely favorable,[5] though some objected that the tale seemed to be told by a narrator who perished with the ship, as the British edition lacked the epilogue recounting Ishmael's survival. American reviewers were more hostile.[6] ";

  cout << "Additive cipher of message \"" << message << "\" with key " << key << endl;

  auto start = high_resolution_clock::now();
  string c = additiveEncipher(message, key);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
 
  cout << c << endl << endl;
  cout << "This took " << duration.count() << " microseconds" << endl;
  // cout << additiveDecipher(c, key) << endl << endl;

  cout << "Parallel additive cipher of message \"" << message << "\" with key " << key << endl;
    
  auto start2 = high_resolution_clock::now();
  std::promise<string> prms;
  std::thread t(parallelAdditiveEncipher, message, key, std::ref(prms));
  std::future<string> ftr = prms.get_future();
  c = ftr.get(); 
  t.join();
  auto stop2 = high_resolution_clock::now();
  auto dur2 = duration_cast<microseconds>(stop2 - start2);
  cout << c << endl; 
  cout << "This took " << dur2.count() << " microseconds" << endl;


  // // Test multiplicative
  // key = 11;
  // message = "Let's talk about it together!";
  // cout << "Multiplicative cipher of message \"" << message << "\" with key " << key << endl;
  // c = multiplicativeEncipher(message, key);
  // cout << c << endl;
  // cout << multiplicativeDecipher(c, key) << endl << endl;

  // // Test affine
  // int keyM = 7;       // Multiplicative key
  // int keyA = 11; // Additive key
  // message = "Meet me at the usual place at eight o'clock";
  // cout << "Affine cipher of message \"" << message << "\" with mult. key " << keyM << " and add. key " << keyA << endl;
  // c = affineEncipher(message, keyA, keyM);
  // cout << c << endl;
  // cout << affineDecipher(c, keyA, keyM) << endl << endl;

  return 0;
}
/*
characters
a-97
b-98
...
z-122
*/
