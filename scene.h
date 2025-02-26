#pragma once
class Scene
{
public:
	Scene()
	{

	}
	~Scene()
	{

	}
	void Init();
	void Draw();
	void Update();
	void End();
	void SetScene(int scene);
	int GetScene();
};
