#include <memory>
#include <iostream>

struct Project
{
	int Id;
	float Progress;
	Project(int id, float progress):
		Id(id), Progress(progress)
	{
		std::cout << "kick off : " << Id << ", " << Progress << std::endl;
	}

	~Project()
	{
		std::cout << "drop off : " << Id << ", " << Progress << std::endl;
	}
};

auto UpdateProgress(std::unique_ptr<Project> InProgress)
{
	InProgress->Progress += 50.0f;
	return InProgress;
}

auto main() -> int
{
	{
		auto NewProject = std::make_unique<Project>(1, 0.0f);
		std::cout << "add Progress : " << NewProject->Id << ", " << NewProject->Progress << std::endl;
		NewProject = UpdateProgress(std::move(NewProject));
		std::cout << "Update Progress : " << NewProject->Id << ", " << NewProject->Progress << std::endl;
	}
	{
		auto SharedProject = std::make_shared<Project>(1, 0.0f);
		auto DepartedProject = SharedProject;
		std::cout << SharedProject.use_count() << std::endl;

		auto WkProject = std::weak_ptr<Project>(SharedProject);
		std::cout << SharedProject.use_count() << std::endl;
		DepartedProject.reset();
		std::cout << SharedProject.use_count() << std::endl;

			
		if (WkProject.expired())
		{
			std::cout << "WkProject Expired" << std::endl;
		}
		else
		{
			std::cout << "WkProject Not Expired" << std::endl;
		}

		auto Locked = WkProject.lock();
		std::cout << SharedProject.use_count() << std::endl;
		Locked.reset();

		SharedProject.reset();
		std::cout << SharedProject.use_count() << std::endl;

		if (WkProject.expired())
		{
			std::cout << "WkProject Expired" << std::endl;
		}
		else
		{
			std::cout << "WkProject Not Expired" << std::endl;
		}

		if (auto Locked2 = WkProject.lock())
			std::cout << Locked2->Progress << std::endl;
	}
	system("pause");
}