function love.load()
	x = 100
end

function love.update(dt)
	if(love.keyboard.isDown("right")) then
		x = x + 100 * dt
	elseif(love.keyboard.isDown("q")) then
		love.exit()
	end
end

function love.draw()
	love.graphics.rectangle("line", x, 100, 400, 200);
end
