#include "Core/Application.h"

#include "AppLayer.h"

int main()
{
    Core::ApplicationSpecification appSpec;
    appSpec.Name = "Architecture";
    appSpec.WindowSpec.Width = 1200;
    appSpec.WindowSpec.Height = 800;

    Core::Application application(appSpec);
    application.PushLayer<AppLayer>();
    application.Run();
}