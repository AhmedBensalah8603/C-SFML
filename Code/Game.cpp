#include"Game.h"
#include"Dimension.h"
#include <string>
#include<sstream>

using namespace sf;
using namespace std;
Game::Game(RenderWindow& window) :
        win(window),
        is_enter_pressed(false),
        run_game(true),
        ziwziw_t3adda(false),
        Chejra_counter(71),
        Chejra_frequency(70),
        score(0),
        best_score(0)
{
	win.setFramerateLimit(60);
	bg_texture.loadFromFile("assets/background-night (2).png");//assets/bg.png
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
	bg_sprite.setPosition(-10.f, 0.f);

	ground_texture.loadFromFile("assets/land.png");
	ground_sprite1.setTexture(ground_texture);
	ground_sprite2.setTexture(ground_texture);

	ground_sprite1.setScale(SCALE_FACTOR, SCALE_FACTOR);
	ground_sprite2.setScale(SCALE_FACTOR, SCALE_FACTOR);

	ground_sprite1.setPosition(0, 578);
	ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().width, 578);

    ready_tex.loadFromFile("assets/message.png");
    ready_spr.setTexture(ready_tex);
    ready_spr.setPosition(200.f, 399.f);

    replay_tex.loadFromFile("assets/replay.png");
    replay_sp.setTexture(replay_tex);
    replay_sp.setScale(1.6f,1.6f);
    replay_sp.setPosition(222.f,540.f);

	game_over.loadFromFile("assets/gameOver.png");
	game_over_sprite.setTexture(game_over);
	game_over_sprite.setPosition(140.f, 200.f);//50.f,200.f

    font3.loadFromFile("assets/arial.ttf");//assets/arial.ttf
	font.loadFromFile("assets/flappy-font.ttf");//assets/arial.ttf

    sound1_tx.loadFromFile("assets/sound+.png");
    sound1_sp.setTexture(sound1_tx);
    sound1_sp.setScale(4.0f,2.5f);
    sound1_sp.setPosition(155, 325);

    sound2_tx.loadFromFile("assets/sound-.png");
    sound2_sp.setTexture(sound2_tx);
    sound2_sp.setScale(4.0f,2.5f);
    sound2_sp.setPosition(155, 325);

    font2.loadFromFile("assets/angrybirds-regular.ttf");//assets
    flappy_ziw.setFont(font2);
    flappy_ziw.setCharacterSize(85);
    flappy_ziw.setFillColor(Color{255, 165, 0});
    flappy_ziw.setPosition(50, 50);//80,110
    flappy_ziw.setString("FLAPPY ZIWZIW");

    start_text.setFont(font);
	start_text.setCharacterSize(48);
	start_text.setFillColor(Color::White);
	start_text.setPosition(38, 650);
	start_text.setString("press Enter to start");

    Good_luck.setFont(font2);
    Good_luck.setCharacterSize(50);
    Good_luck.setFillColor(Color::White);
    Good_luck.setPosition(38, 450);
    Good_luck.setString("Good Luck !!!");

	score_text.setFont(font);
    score_text.setFillColor(Color::White);
    score_text.setCharacterSize(35);
	score_text.setPosition(40, 15);
	score_text.setString("0");

    BM_tex.loadFromFile("assets/Bronze-Medal__1_-removebg-preview.png");
    BM_sp.setTexture(BM_tex);
    BM_sp.setPosition(176,394);

    SM_tex.loadFromFile("assets/Silver-Medal__1_-removebg-preview.png");
    SM_sp.setTexture(SM_tex);
    SM_sp.setPosition(180,394);

    GM_tex.loadFromFile("assets/Gold-Medal__1_-removebg-preview (1).png");
    GM_sp.setTexture(GM_tex);
    GM_sp.setPosition(180,394);

    new_tex.loadFromFile("assets/new-removebg-preview.png");
    new_sp.setTexture(new_tex);
    new_sp.setPosition(320, 417);
    new_sp.setScale(0.5f,0.5f);

    pause_tex.loadFromFile("assets/pause.png");
    pause_sp.setTexture(pause_tex);
    pause_sp.setScale(1.35f,1.35f);
    pause_sp.setPosition(550, 15);

    help_tex.loadFromFile("assets/HelpButton__1_-removebg-preview.png");
    help_sp.setTexture(help_tex);
    help_sp.setPosition(240, 2);

    resume_tex.loadFromFile("assets/resume.png");
    resume_sp.setTexture(resume_tex);
    resume_sp.setScale(1.35f,1.35f);
    resume_sp.setPosition(550, 15);

    pause_tab_texture.loadFromFile("assets/pause_tab.jpg");
    pause_tab_sprite.setTexture(pause_tab_texture);
    pause_tab_sprite.setScale(1.6f,1.8f);
    pause_tab_sprite.setPosition(99.f, 225.f);

    best_score_text.setFont(font);
	best_score_text.setCharacterSize(24);
	best_score_text.setFillColor(Color::White);
	best_score_text.setPosition(393, 450); //386 369
	best_score_text.setString("");

    font3.loadFromFile("assets/arial.ttf");
    text_help.setFont(font3);
    text_help.setCharacterSize(35);
    text_help.setFillColor(Color::White);
    text_help.setPosition(38, 150);
    text_help.setString("Tap Space to make Ziwziw fly \n \n \nBe careful !, hitting trees ,ground\nor sky will lead to your defeat !! \n\n\n\t\t ");


	deadSound.openFromFile("assets/sfx/dead.ogg");
	flapSound.openFromFile("assets/sfx/flap.ogg");
	scoreSound.openFromFile("assets/sfx/score.ogg");
	bgSound.openFromFile("assets/sfx/song.mp3");
    pauseSound.openFromFile("assets/sfx/pause.mp3");
	flapSound.setVolume(20);
	scoreSound.setVolume(50);
	deadSound.setVolume(100);
    pauseSound.setVolume(50);
    bgSound.setVolume(0);
	bgSound.play();

	bgSound.setLoop(true);

	Chejra::loadTextures();

    // kifech na9n3ek belli hetha lkol constructeur XD

}

void Game::doProcessing(Time& dt)
{
    // ay 7aja tet7arrak mawjouda fil hal fonction XD
	if (is_enter_pressed)
	{
        // Déplacement mta3 l 9e3a bech na3tiw l jeu un  effet de défilement
		moveGround(dt);

        // houni bech na3mlou el génération mta3 chejrat (mouch nafs el taille ) b este3mel vector
		if (Chejra_counter > Chejra_frequency)
		{
			Chejrat.push_back(Chejra(dist(rd)));
            Chejra_counter = 0;
		}
		Chejra_counter++;

		for (int i = 0; i < Chejrat.size(); i++)
		{
			Chejrat[i].update(dt);
			if (Chejrat[i].getRightBound() < 0)
			{
				Chejrat.erase(Chejrat.begin() + i);
			}
		}
        // nthabtou el collision
		checkCollisions();
        // hne bech ne7sbou score w best score
		checkScore();
	}
    // l hne kifech n7arkou el 3asfour n5alliwah ytiir
	Asfour.update(dt);
}

void Game::startGameLoop()
{
	Clock clock;

	while (win.isOpen()) {
        Time dt = clock.restart();
        Event event;
        //Event Loop
        while (win.pollEvent(event)) {
            if (event.type == Event::Closed) {
                win.close();
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2i mousePos = Mouse::getPosition(win);
                FloatRect pauseBounds = pause_sp.getGlobalBounds();
                if (pauseBounds.contains(mousePos.x, mousePos.y)) {
                    pauseSound.play();
                    is_paused = !is_paused;
                }
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2i mousePos = Mouse::getPosition(win);
                FloatRect helpBounds = help_sp.getGlobalBounds();
                if (helpBounds.contains(mousePos.x, mousePos.y)) {
                    pauseSound.play();
                    is_help = !is_help;
                }

            }
            // Check for mouse click on sound1_sp and sound2_sp
            if (Mouse::isButtonPressed(Mouse::Left) && (sound2_sp.getGlobalBounds().contains(Mouse::getPosition(win).x, Mouse::getPosition(win).y))) {
                sound_on = true;
                bgSound.setVolume(10);
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sound1_sp.getGlobalBounds().contains(Mouse::getPosition(win).x, Mouse::getPosition(win).y)) {
                sound_on = false;
                bgSound.setVolume(0);
            }

            if (event.type == Event::KeyPressed && run_game) {
                if (event.key.code == Keyboard::Enter && !is_enter_pressed) {

                    is_enter_pressed = true;
                    start_text.setString("");
                    flappy_ziw.setString("");
                    ready_spr.setPosition(-200.f, -200.f);
                    Asfour.setShouldFly(true);
                }
                if (event.key.code == Keyboard::Space && is_enter_pressed) {
                    Asfour.flapZiwziw(dt);
                    flapSound.play();


                }

            }
            if (event.key.code == Keyboard::Enter && !run_game)
                restartGame();
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2i mousePos = Mouse::getPosition(win);
                FloatRect replayBounds = replay_sp.getGlobalBounds();
                if (replayBounds.contains(mousePos.x, mousePos.y)) {
                    restartGame();
                }

            }
        }


        // hne bech ki famma pause kol chay(les mouvements lkol) ye9ef bi blastou
		if(!is_paused)doProcessing(dt);
		draw();
		win.display();
	}
}

void Game::checkCollisions()
{
    // houni bech nthabtou ken l3asfour 4rab chejra wela 9e3a wela smee rahou tsiir collision
	if (Chejrat.size() > 0)
	{
		if (Chejrat[0].Chejra_fou9.getGlobalBounds().intersects(Asfour.Ziwziw_Sprite.getGlobalBounds()) ||
            Chejrat[0].Chejra_louta.getGlobalBounds().intersects(Asfour.Ziwziw_Sprite.getGlobalBounds()) ||
            Asfour.Ziwziw_Sprite.getGlobalBounds().top >= 540)
		{
			is_enter_pressed = false;
			run_game = false;
			deadSound.play();
			bgSound.stop();
		}
		deadSound.play();
	}

}

void Game::checkScore()
{
	if (Chejrat.size() > 0)
	{
        // houni bech na3rfou lasfour t3adda bin chijrtin walla w l variable w kenou t3adda nzidou score
		if (!ziwziw_t3adda)
		{
			if (Asfour.Ziwziw_Sprite.getGlobalBounds().left > Chejrat[0].Chejra_fou9.getGlobalBounds().left &&
                Asfour.getRightBound() < Chejrat[0].getRightBound())
			{
                ziwziw_t3adda = true;
			}
		}
		else
		{
			if (Asfour.Ziwziw_Sprite.getGlobalBounds().left > Chejrat[0].getRightBound())
			{
				score++;
				score_text.setString("" + toString(score));
                ziwziw_t3adda = false;
                // houni kol 5 points bech na3mlou effet sonore
				if (score % 5 == 0)
					scoreSound.play();
			}
		}
        // hnee bech na3lou mise a jour mta3 best score
		if (score >= best_score){
			best_score = score;
            if(best_score  )is_new=true;
            if(best_score==0)is_new=false;

        }
        // hne bech na3rfou ken hethi awel marra yousel lel best score hetha walla
        else
            is_new=false;
	}
}

void Game::draw() {

    //hnee bech nersmou el sprites lkol
    win.draw(bg_sprite);
    for (Chejra &grave: Chejrat) {
        win.draw(grave.Chejra_fou9);
        win.draw(grave.Chejra_louta);
    }

    win.draw(ground_sprite1);
    win.draw(ground_sprite2);
    if(!is_help)win.draw(Asfour.Ziwziw_Sprite);

    if (is_paused && run_game && !is_help ) {
        win.draw(pause_tab_sprite);
        flappy_ziw.setPosition(-200,-200);
        win.draw(resume_sp);
        best_score_text.setString("" + toString(best_score));
        best_score_text.setPosition(420, 375);
        best_score_text.setCharacterSize(30);
        win.draw(best_score_text);
        if(!sound_on)win.draw(sound2_sp);
        else win.draw(sound1_sp);
        score_text.setCharacterSize(30);
        score_text.setPosition(420, 285);
        win.draw(score_text);
    }
    // hnee el sprites mta3 el game over
    if (!run_game)
    {
        win.draw(game_over_sprite);
        win.draw(flappy_ziw);
        best_score_text.setPosition(393, 450);
        best_score_text.setString("" + toString(best_score));
        win.draw(best_score_text);
        score_text.setCharacterSize(24);
        score_text.setPosition(393, 376);
        win.draw(score_text);
        if (is_new) win.draw(new_sp);
        //hnee 3anna l gestion mta3 les médailles
        if (score >=5 && score<10) win.draw(BM_sp);
        if (score >=10 && score<15) win.draw(SM_sp);
        if (score>= 15)win.draw(GM_sp);
        ready_spr.setPosition(-200.f, -200.f);
        win.draw(replay_sp);
    }

    if(is_help && !is_paused && run_game && !is_enter_pressed){
        win.draw(help_sp);
        win.draw(Good_luck);
        win.draw(text_help);

    }


    if(! is_paused && !is_help && run_game && !is_enter_pressed)
    {
        flappy_ziw.setPosition(50, 99);
        win.draw(flappy_ziw);
        win.draw(help_sp);
        win.draw(ready_spr);
        win.draw(start_text);
    }
    if(! is_paused && run_game && !is_help)win.draw(pause_sp);
    score_text.setPosition(40, 15);
    score_text.setCharacterSize(50);
    if(!is_paused && !is_help && run_game)win.draw(score_text);





}

void Game::moveGround(Time& dt)
{
    // hethi fonction li t7arrak l 9e3a
	ground_sprite1.move(-move_speed * dt.asSeconds(), 0.f);
	ground_sprite2.move(-move_speed * dt.asSeconds(), 0.f);

	if (ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width < 0)
	{
		ground_sprite1.setPosition(ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width, 578);
	}
	if (ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width < 0)
	{
		ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width, 578);
	}
}

void Game::restartGame()
{
    // hne l principe mta3 replay mba3d le5sara
    Asfour.resetZiwziwPosition();
	Asfour.setShouldFly(false);
	is_enter_pressed = false;
    Chejra_counter = 71;
	Chejrat.clear();
	score = 0;
    flappy_ziw.setString("FLAPPY ZIWZIW");
	score_text.setString("0");
    score_text.setCharacterSize(35);
    score_text.setPosition(40, 15);
    ready_spr.setPosition(200.f, 399.f);
    run_game = true;
	start_text.setString("press Enter to start");
    win.draw(start_text);
	bgSound.play();
}

//  override mta3 fonction to string pour la bonne gestion des chaines de caractères
std::string Game::toString(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}